#include "lecture.h"

int nombre_sommets(char *fic){
	FILE *F=fopen(fic,"r");
	int nbr = 0;
	char caractere1=' ';
	
	caractere1 = ' '; // initialisation
	while ( 1 ){
		caractere1 = fgetc(F);
		if(caractere1 == '\n'){
			caractere1 = fgetc(F);
			if (caractere1 == 'V'){ // on a trouve un retour a la ligne donc si la prochaine lettre est un V on doit sortir
				break;
			}
		}
	}
	ungetc(caractere1 , F); // on remet le V ..	

	caractere1 = ' '; // initialisation
	while ( 1 ){
		caractere1 = fgetc(F);
		if(caractere1 == '\n'){
			nbr ++;
			caractere1 = fgetc(F);
			if (caractere1 == 'E'){ // on a trouve un retour a la ligne donc si la prochaine lettre est un E on doit sortir
				break;
			}
		}
	}
	
	fclose(F);
	return nbr;
}




GRAPHE lecture_sommet(char *fichier,GRAPHE g){
	int i=0,j;
	int num_sommet,num_ligne;
	char caractere;
	//ouverture de fichier
	FILE *F = fopen(fichier, "r");
	//ignorer le 3 premieres ligne de fichier
	char caractere1 = ' '; // initialisation
	while ( 1 ){
		caractere1 = fgetc(F);
		if(caractere1 == '\n'){
			caractere1 = fgetc(F);
			if (caractere1 == 'V'){ // on a trouve un retour a la ligne donc si la prochaine lettre est un V on doit sortir
				break;
			}
		}
	}
	ungetc(caractere1 , F); // on remet le V ..		

	//recuperer les infos de chaque station (sommet)
	for(i=0;i<g.nb_sommets;i++){
		caractere=fgetc(F); // caractere V inutile ..
		fscanf(F, "%d %d", &num_sommet,&num_ligne);
		j = 0;
		caractere = fgetc(F); // pour se débarasser de l'espace ' '
		while(1){	
			caractere = fgetc(F);
			if (caractere != '\n' ){
				g.tab_sommets[i].nom_station[j]=caractere;
				j++;	
			}
			else break;
		}
		g.tab_sommets[i].num_station=num_sommet;
		g.tab_sommets[i].num_metro=num_ligne;
	}
	fclose(F);
return g;
}

GRAPHE lecture_arcs(char *fichier,GRAPHE g){
	char caractere1;
	//ouverture de fichier

	FILE *F = fopen(fichier, "r");
	//caractere1 = fgetc(F) ;
	
	// ignorer les ligne de sommet 
	caractere1 = ' '; // initialisation
	while ( 1 ){
		caractere1 = fgetc(F);
		if(caractere1 == '\n'){
			caractere1 = fgetc(F);
			if (caractere1 == 'E'){ // on a trouve un retour a la ligne donc si la prochaine lettre est un E on doit sortir
				break;
			}
		}
	}
	ungetc(caractere1 , F); // on remet le E ..	
	
	
	// initialisation des arcs du graphe
	
	for (int i = 0; i < g.nb_sommets; i++) {
		for (int j = 0; j < g.nb_sommets; j++) {
			g.tab_arc[i][j].successeur_final = -1; //pas de terminus
			g.tab_arc[i][j].poid = -1; // pas d'arcs
		}
	}
	
	int scan=0; //valeur de retour par fscanf
	int som1,som2; //les 2 sommets qui relier par l'arc
	int dure; // temps en seconde
	int direction1,direction2; //terminus
	
	// remplir les arcs du graphe 
	
	while (scan != -1) {	
		
		scan=fscanf(F, "%c %d %d %d %d %d", &caractere1, &som1, &som2, &dure,&direction1, &direction2);
		if(scan != -1){
			
			//remplir l'arc aller
		
			g.tab_arc[som1][som2].poid = dure;
			g.tab_arc[som1][som2].successeur_final = direction1;
			
			//rempir l'arc retour 
			
			g.tab_arc[som2][som1].poid = dure;
			g.tab_arc[som2][som1].successeur_final = direction2;
			
		}
	}
	fclose(F);
	return g;
}
