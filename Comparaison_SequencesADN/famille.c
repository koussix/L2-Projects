#include <stdio.h>
#include <stdlib.h>
#include "famille.h"

int est_vide_famille(famille f){
	if(f==NULL) return 1;
	else return 0;
}

famille ajouter_nouvelle_famille(famille f,int val){ //on ajoute une nouvelle famille f dont l'element le plus frequent 
	struct liste_famille *e;							//est l'element dont l'id est le parametre val
	e=malloc(sizeof(struct liste_famille));
	if(!e){ fprintf(stderr,"ERREUR LORS DE LA CREATION \n");
			exit(EXIT_FAILURE);
		}
	e->id[0]=val;
	e->nb_elem=1;	//on initialise notre champ nb_elem a 1
	for(int i=1;i<Nb_fich;i++){
		e->id[i]=-1;}
	e->suiv=NULL;
	if(est_vide_famille(f)){
		 return e;
	 }
	struct liste_famille *l=f;
	while(f->suiv != NULL){
		f=f->suiv; }
	f->suiv=e;
	return l;
}

famille inserer_dans_famille(famille f,int val){
	if(est_vide_famille(f)){ printf("ERREUR DANS INSERER FAMILLE");}
	int i=0;
	famille l=f;
	while( l->suiv!=NULL ){ 
	l=l->suiv; }
	while(l->id[i]!=-1){
		i++;}
	l->id[i]=val;
	l->nb_elem++;
	return f;
}
int nb_famille(famille f){
	int nb=0;
	while( f!=NULL ){
		nb++;
		f=f->suiv;
	}
	return nb;
}
void affiche_famille(famille f,seq *tab_seq){
	int i;
	int j=0;
	while(f != NULL){
		i=0;
		j++;
		printf("Affichage de la famille %d dont le nombre d'elem est= %d \n",j,f->nb_elem);
		while((f)->id[i] != -1 ){
			printf("id=>%2d | sequence: ",(f)->id[i]);
			for(int k=1;k<(tab_seq[k].n)+1 ; k++){
				printf("%c",tab_seq[(f)->id[i]].t[k]);
			}
			printf("\n");
			i++;
		}
		printf("########### \n");
		f=f->suiv;
	}
}

famille crea_famille(famille f, Tri_d *d2,seq *tab_seq){
	f=NULL;
	int nb_ajout;
	int tab_freq[Nb_fich];	//pour verifier a chaque fois combien de fois l'on croise un ID
	int tab_hachage[Nb_fich]; //pour verifier si l'element a déja été pris ou non .. (on note 1 déja pris 0 non pris)
	nb_ajout=0;
	float distance_min=0;
	int i=0; 
	int j=0;
	int x; // recuperer la valeur la plus frequente
	int k; // Utiliser exclusivement pour les boucles de 1..n
	int bool; // prendra les valeurs 0 ou 1
	
	//INITIALISATION DU TAB FREQUENCE
	for(k=0;k<Nb_fich;k++)
		tab_freq[k]=0;
	//INITIALISATION DE LA TAB HACHAGE
	for(k=0;k<Nb_fich;k++)
		tab_hachage[k]=0;
	
	//DÉBUT DE TRAITEMENT
	
	while(nb_ajout<20){
		distance_min=d2[i].reel; //  Case du tableau trié == distance minimale actuelle
		j=i;
		while(d2[j].reel==distance_min){
			// ### DANS Le premier while d[j]
			tab_freq[d2[j].id1]++;
			tab_freq[d2[j].id2]++;
			j++;
		}
		
		while(d2[i].reel==distance_min){
			bool=1;
			x=-1; //initialisation de l'indice ou se trouve notre valeur la plus frequente 
			int temp=0; // on utilisera pour trouver la frequence la plus grande ..
			for(k=0;k<Nb_fich;k++){
				if(temp<tab_freq[k]){ temp=tab_freq[k]; x=k;
			}
		}
		while((tab_hachage[x]!=0) && (bool==1)){ //veut dire que notre x a déja été pris on prend donc l'element le plus frequent sauf le x lui meme
			tab_freq[x]=0;
			x=0;
			temp=0; 
			for(k=0;k<Nb_fich;k++){
				if(temp<tab_freq[k]){temp=tab_freq[k];
					 x=k;}
			}
			if(temp == 0 ){// veut dire que la frequence la plus grande est de 0...
				bool= 0;}
		}
		if( bool == 0 ){ // il n' y a rien a ajouter on passe a l'élement suivant
			i++;
		}
		else {
		
		f=ajouter_nouvelle_famille(f,x);
		
		tab_hachage[x]=1; //element ajouté donc on ne l'ajoute plus
		tab_freq[x]=0; //element ajouté donc on remet sa frequence a 0 pour qu'il ne nous gene pas dans les prochain tours de boucle
		nb_ajout++;
		for(k=0;k<Nb_fich;k++){
			if((tab_freq[k]!=0)&&(tab_hachage[k]==0)&&(calcul_distance_2(tab_seq[x],tab_seq[k]))==distance_min){
						f=inserer_dans_famille(f,k);
						tab_hachage[k]=1;
						nb_ajout++;
						tab_freq[k]=0;
						i++;
					}
				
			}
		}
	}
	}
	return f;
}

