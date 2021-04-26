#include <stdio.h>
#include <stdlib.h>
#include "distance.h"
#include "sequence.h"
#define Taille_tab_tri (Nb_fich*(Nb_fich-1))/2

dis creer_distance(){
	dis di;
	di.mat= NULL;
		
return di;
}


float compare_carac(char a,char b){
	if(a=='A'){
		switch(b){
			case 'C' : return 2;
			case 'G' : return 1;
			case 'T' : return 2;
			case 'A' : return 0;
			default : return 1.5;
		}
	}
	if(a=='C'){
		switch(b){
			case 'C' : return 0;
			case 'G' : return 2;
			case 'T' : return 1;
			case 'A' : return 2;
			default : return 1.5;
		}
	}
	if(a=='G'){
		switch(b){
			case 'C' : return 2;
			case 'G' : return 0;
			case 'T' : return 2;
			case 'A' : return 1;
			default : return 1.5;
		}
	}
	if(a=='T'){
		switch(b){
			case 'C' : return 1;
			case 'G' : return 2;
			case 'T' : return 0;
			case 'A' : return 2;
			default : return 1.5;
		}
	}
return 1.5;
}

float compare_seq(seq s1,seq s2){
	int i=1; int j=1; float h=0;
	while((i<(s1.n)) || (j<(s2.n))){
		h=h+compare_carac(s1.t[i],s2.t[j]);	
		i++;
		j++;
	}
return h;
}

dis distance_1(char *nrep){  //premiere methode de calcul des distance
	seq *tab_seq=stockage_seq(nrep);
	int nb=nombre_fichiers(nrep);
	dis di;
	di=creer_distance();
	di.mat=malloc(nb*sizeof(float*));
	if(!di.mat) exit(3);
	for(int i=0;i<nb;i++){
		di.mat[i]=malloc(nb*sizeof(float));
		if(!di.mat[i]){
			fprintf(stderr,"erreur malloc distance");
			exit(4);
		}
	}
	int i,j;
	for(i=0;i<nb;i++){
		for(j=i+1;j<nb;j++){
			di.mat[i][j]=compare_seq(tab_seq[i],tab_seq[j]);  //comparaison caractere par caractere dans campare_seq
		} 
			}
return di;	
}
float min(float a,float b,float c){
	float temp;
	if(a<b){temp=a;}
	else temp=b;
	if(temp<c){return temp;}
	else return c;
}
float calcul_distance_2(seq s1,seq s2){
	int n=(s1.n); 
	int m=(s2.n);
	float tab[n][m];
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){ 
			if(i==0){
				tab[i][j]=j*1.5;} //on remplis la premiere ligne en simulant des insertion de seq2 dans seq1
			else if(j==0){
				tab[i][j]=i*1.5;} //on remplis la premiere ligne en simulant des insertion de seq1 dans seq2
			else {
			float f1=tab[i-1][j-1]+compare_carac(s1.t[i],s2.t[j]); //aucune insertion n'est faite 
			float f2=tab[i-1][j]+1.5;	//insertion
			float f3=tab[i][j-1]+1.5;	//insertion
			tab[i][j]=min(f1,f2,f3);
			}
	}
}
	return tab[n-1][m-1];
}

dis distance_2(char* nrep){  // 2eme methode de calcul des distances entre sequences
	seq *tab_seq=stockage_seq(nrep); //on recupere notre tableau de sequence
	int nb=nombre_fichiers(nrep); 
	dis di;
	di=creer_distance();
	di.mat=malloc(nb*sizeof(float*));
	if(!di.mat) exit(3);
	for(int i=0;i<nb;i++){
		di.mat[i]=malloc(nb*sizeof(float));
		if(!di.mat[i]){
			fprintf(stderr,"erreur malloc distance");
			exit(4);
		}
	}
	int i,j;
	for(i=0;i<nb;i++){
		for(j=i+1;j<nb;j++){
			di.mat[i][j]=calcul_distance_2(tab_seq[i],tab_seq[j]);
		} 
			}
	return di;
}


Tri_d *copie_trie(dis d2, Tri_d *tab){ //prend notre matrice distance 2 en paramettre et renvoie un tableau trié
	//Tri_d *tab;
	tab=malloc(Taille_tab_tri* (sizeof(Tri_d)));
	int i=0;
	int j=0;
	printf(" NOMBRE FICHIERS %d\n",Nb_fich);
	int k=0; //indice du tableau tab
	for(i=0;i<Nb_fich-1;i++){
		for(j=i+1;j<Nb_fich;j++){
			tab[k].id1=i;
			tab[k].id2=j;
			tab[k].reel=d2.mat[i][j];
			k++;
		}
	}
	// ###  TRI A BULLE ###
	Tri_d elem;
	for(i=0;i<Taille_tab_tri;i++){
		for(j=Taille_tab_tri-1;j>i;j--){
			if(tab[j].reel<tab[j-1].reel){
				elem=tab[j-1];
				tab[j-1]=tab[j];
				tab[j]=elem;
			}
		}
	}
	// #########################
	//printf("## DANS LA FONCTION COPIE ## \n");
	
	return tab;
}

void affiche_distance_trier(Tri_d *tab){
	
	for(int k=0;k<Taille_tab_tri;k++){
		printf("distance entre s%02d et s%02d =%02.2f\n",tab[k].id1,tab[k].id2,tab[k].reel);
	}
	
	
}

void affiche_dis(dis di){
	int i,j;
	for(i=0;i<Nb_fich;i++)
		for(j=i+1;j<Nb_fich;j++){
		printf("la distance entre la sequence %d et %d est ",i,j);
		printf("%f\n",di.mat[i][j]);
	}
}


