#include "lecture.h"
#include <limits.h>
#define INFINI 1000000

GRAPHE graphe_initialiser(int nb_sommets){
	GRAPHE g;
	g.nb_sommets= nb_sommets;

	g.tab_sommets = malloc(nb_sommets *(sizeof(SOMMET)));
	for(int i = 0 ; i<nb_sommets ; i++){
		g.tab_sommets[i].num_station=0;
		g.tab_sommets[i].num_metro = 0;
		for(int j=0 ; j<TAILLE_NOM ;j++){
			g.tab_sommets[i].nom_station[j]='\0';
		}
	}

	g.tab_arc = malloc (nb_sommets *(sizeof(ARC *)));
	for (int i=0 ; i<nb_sommets ; ++i){
		g.tab_arc[i] = malloc(nb_sommets*(sizeof(ARC)));
	}



	return g;
}	


GRAPHE remplir_graphe(){
	GRAPHE G;
	int nb_sommet=nombre_sommets(FICHIER);
	G=graphe_initialiser(nb_sommet);
	G=lecture_sommet(FICHIER,G);
	G=lecture_arcs(FICHIER,G);
	return G;
}


int chercher_num_station(GRAPHE g,char *station,int *num_st){
	int compteur=0; //int booleen;
	for(int i=0;i<g.nb_sommets;i++){
		if(strcmp(station , g.tab_sommets[i].nom_station) == 0){
			if(compteur == 0){
				*num_st = i ;
				//*num_metro = i ;
			}
			compteur ++;

		}
	}
	return compteur;
}

void afficher_graphe(GRAPHE g){
	// affichage les sommets
	for (int i = 0; i < g.nb_sommets; i++) {
		printf("la %d station qui est  %s sa ligne est %d\n",
		g.tab_sommets[i].num_station,g.tab_sommets[i].nom_station,g.tab_sommets[i].num_metro);
	}	
	// affichage les arcs 
	for (int i = 0; i < g.nb_sommets; i++) {
		for (int j = 0; j < g.nb_sommets; j++) {
			if(g.tab_arc[i][j].poid != -1 ){
				printf("[%d , %d , %d] ",
				i,g.tab_arc[i][j].poid,j);
				if(g.tab_arc[i][j].successeur_final != 1111){
					printf("Direction : %s",
					g.tab_sommets[g.tab_arc[i][j].successeur_final].nom_station);
				}
				else{
					printf("on est dans la meme gare");
				}
				printf("\n");
			}
		}
	}
	
}


CHEMIN *chemin_ajouter_sommet_deb(CHEMIN *l, SOMMET s){
	CHEMIN *new = malloc(sizeof(CHEMIN));
	new->station.num_station=s.num_station;
	strcpy(new->station.nom_station , s.nom_station );
	new->station.num_metro= s.num_metro ;
	new->suiv = NULL;
	if(!l){
		return new;
	}
	else{
		new->suiv = l ;
		return new;
	}

}

void chemin_liberer( CHEMIN *l){
	CHEMIN *courant =l;
	while (l){
		l=l->suiv;
		free(courant);
		courant =l;
	}
	free(courant);
}

void afficher_chemin( CHEMIN *l ){  //celle ci est une version qui détaille chaque sommet ( mais ce n'est pas la fonction d'affichage du prograrmme )
	CHEMIN *tmp = l;
	if(!tmp){
		fprintf(stderr, "ERROR : PAS DE CHEMIN \n" );
		exit(1);
	}
	int nb = 0; // 0 c'est le départ
	while( tmp ){
		printf("\nSOMMET num : %d \n --->num_station = %d\n ----> nom_station =%s\n ----> num_metro =%d]\n ",nb ,\
			tmp->station.num_station, tmp->station.nom_station , tmp->station.num_metro );
		tmp= tmp->suiv;
		nb++;
	}
}

void graphe_liberer(GRAPHE g){
	free(g.tab_sommets);
	for(int i=0 ; i< g.nb_sommets ;i++){
		free(g.tab_arc[i]);
	}
	free(g.tab_arc);
}


DIJKSTRA remplir_chemin(DIJKSTRA D , GRAPHE g,int tab_pere[]){
	int sommet_courant;
	int s = D.id_fin;
	D.plus_court = chemin_ajouter_sommet_deb(D.plus_court , g.tab_sommets[s]);
	
	D.duree = 0 ;
	while (s != D.id_debut) {
		sommet_courant = s;
		s = tab_pere[sommet_courant];
		D.duree += g.tab_arc[sommet_courant][tab_pere[sommet_courant]].poid;
		D.plus_court = chemin_ajouter_sommet_deb(D.plus_court, g.tab_sommets[s]);
	
	}
	//afficher_chemin(D.plus_court);
	return D;
}


DIJKSTRA court_chemin (GRAPHE g, int deb , int fin){
	// initialisation 
	DIJKSTRA D ;
	D.id_debut = deb ;
	D.id_fin = fin ;
	D.plus_court = NULL;

	int sommet_traite[g.nb_sommets];// tab de hashage 0 si n'est pas traité 1 sinon
	int pere_sommet[g.nb_sommets];	//contient le pere du sommet i par lequel le chemin est le plus court
	int distance[g.nb_sommets];	//contient les plus petites distances entre le sommet de depart et lelement
	//initialisation des tableaux 
	for (int i = 0 ; i< g.nb_sommets ; i++){
		sommet_traite[i] = 0 ;
	}
	for( int i =0 ; i< g.nb_sommets ; i++ ){
		pere_sommet[i] = -1 ; // aucun pere
	}
	for( int i = 0 ; i< g.nb_sommets ; i++ ){
		distance[i] = INFINI; // infini
	}
	int nb_traite =0 ; // un compteur qui va compter le nombre de sommet trariter pour ne pas avoir a re parcourir notre tableau a chauqe fois
	
	//initialisation du sommet de depart 
	distance[deb] = 0;
	sommet_traite[deb] = 1 ;
	nb_traite ++ ;

	for (int i = 0; i < g.nb_sommets; i++) {
		if (g.tab_arc[deb][i].poid != -1 ) { /// il ya une maniere d'atteindre directement le prochain sommet
			distance [i] = g.tab_arc[deb][i].poid;
			pere_sommet [i] = deb ;
		} else
			distance[i] = INFINI ; // pas de relation pere fils
	}

	int min;
	int sommet_a_traite = deb ; // initialisation

	while( nb_traite < g.nb_sommets ){
		min =  INFINI;
		for( int i = 0 ; i<g.nb_sommets ; i++){ // prochain sommet a traité est celui etant le plus proche
			if (( sommet_traite[i] == 0 ) && (distance[i] < min )){
				sommet_a_traite = i ;
				min = distance[i] ; 
			}

		}
		sommet_traite[sommet_a_traite] = 1 ;
		nb_traite ++; // on traite un nouveau sommet
		//on améliore les plus petite distance voisines du sommet si l'on peut 
		for (int i = 0; i < g.nb_sommets; i++) {	
			if (g.tab_arc[sommet_a_traite][i].poid != -1 ) {
				if (distance [i] >= (distance[sommet_a_traite] + g.tab_arc[sommet_a_traite][i].poid)) { //on peut améliorer
					distance[i] = distance[sommet_a_traite] + g.tab_arc[sommet_a_traite][i].poid;
					pere_sommet[i] = sommet_a_traite;	//pere du sommet i le sommet qu'on a utiliser pour trouvé la distance
				}
			}
		}


	}
	

	D = remplir_chemin(D , g , pere_sommet);


	return D;
}




void dijkstra_liberer(DIJKSTRA d){
	chemin_liberer(d.plus_court);
}

void affichage_trajet(DIJKSTRA D,GRAPHE G){
	printf("\033[31m");
	printf("\nVous arriverez à votre destination dans : %ld min \n",(D.duree/60));
	printf("\033[00m");
	printf("\x1b[34;01m\n");
		printf("we are here\n");

	char *station1 = strdup(D.plus_court->station.nom_station);
	char *station2 = strdup(D.plus_court->suiv->station.nom_station);

	if(strcmp(station1,station2)==0){
		printf("Vous avez rentré la même ligne !\n");
		return ;
	}

	if(D.plus_court->station.num_metro == 30 || D.plus_court->station.num_metro == 70 ){
		printf("----> Vous étes à %s, ligne %dbis\n",D.plus_court->station.nom_station, D.plus_court->station.num_metro/10);
	}
	else{
		printf("----> Vous étes à %s, ligne %d\n",D.plus_court->station.nom_station, D.plus_court->station.num_metro);
	}
	
	if(strcmp(D.plus_court->station.nom_station, D.plus_court->suiv->station.nom_station )== 0){
		D.plus_court=D.plus_court->suiv;
		if(D.plus_court->station.num_metro == 30 || D.plus_court->station.num_metro == 70 )
			printf("--> Changement de ligne ! allez vers la ligne %dbis \n",D.plus_court->station.num_metro/10 );
		else
			printf("--> Changement de ligne ! allez vers la ligne %d \n",D.plus_court->station.num_metro ) ;
	}

	if(D.plus_court->suiv != NULL){
		if((D.plus_court->station.num_metro != 30) && (D.plus_court->station.num_metro != 70)){
			printf("--> Prenez la ligne %d direction %s\n",D.plus_court->station.num_metro,G.tab_sommets[G.tab_arc[D.plus_court->station.num_station][D.plus_court->suiv->station.num_station].successeur_final].nom_station);
		}
		else{
			printf("--> Prenez la ligne %dbis direction %s\n",D.plus_court->station.num_metro/10,G.tab_sommets[G.tab_arc[D.plus_court->station.num_station][D.plus_court->suiv->station.num_station].successeur_final].nom_station);
		}
	}

	while( D.plus_court->suiv != NULL ){
		if(D.plus_court->station.num_metro != D.plus_court->suiv->station.num_metro){
			D.plus_court=D.plus_court->suiv;
			printf("--> Descendez dans la station %s\n",D.plus_court->station.nom_station);
			if((D.plus_court->station.num_metro != 30) && (D.plus_court->station.num_metro != 70)){
				printf("--> Et Prenez la ligne %d direction %s\n",D.plus_court->station.num_metro,G.tab_sommets[G.tab_arc[D.plus_court->station.num_station][D.plus_court->suiv->station.num_station].successeur_final].nom_station);
			}
			else{
				printf("--> Et Prenez la ligne %dbis direction %s\n",D.plus_court->station.num_metro/10,G.tab_sommets[G.tab_arc[D.plus_court->station.num_station][D.plus_court->suiv->station.num_station].successeur_final].nom_station);
			}
		}
		else{
			D.plus_court=D.plus_court->suiv;
		}
	}	
	printf("--> Decsendez à la station %s (Vous êtes arrivé à votre destination)\n",D.plus_court->station.nom_station);
	printf("\033[00m\n");	
}