#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <dirent.h>
#include "sequence.h"
#include "distance.h"

#define TAILLE_CHN 50


seq creer(int id){
	seq s;
	s.id=id;
	s.t=NULL;
	return s;
}

int taille(char* nomfic){
	FILE *G;
	G = fopen(nomfic,"r");

	int t=0;
	while(fgetc(G) != EOF) 
		t++;

	fclose(G);

	return t;
}

int nombre_fichiers(char *nrep){
	struct dirent *d;
	//---

	DIR *dir = opendir(nrep);
	if(dir==NULL) 
		exit(1);

	int n=0;
	while( (d=readdir(dir)) !=NULL ){
		if((d->d_name[0]) !='.'){
			n++;
		}
	}
	closedir(dir);
	
	return n;
}

struct noms_sequences nom_nb(char* nrep) {
	struct noms_sequences tab;
	//-----

	tab.n = nombre_fichiers(nrep);
	//printf("Nombre de fichiers : %d\n",tab.n);
	
	tab.nom = malloc(tab.n*sizeof(char*));
	int i;
	for(i=0; i<tab.n; i++){
		tab.nom[i]=malloc(TAILLE_CHN*sizeof(char));
	}

	DIR *dir;
	dir = opendir(nrep);
	if(dir==NULL) 
		exit(1);

	struct dirent *d;
	int j=0;
	while (((d=readdir(dir))!=NULL)){
		if((d->d_name[0]) !='.'){
			strcpy(tab.nom[j], d->d_name);
		//printf("Fichiers#1: %s\n",tab.nom[j]);
			j++;
		}
	}
	closedir(dir);
	return tab;
}

seq lecture(seq s,char* nomfich,char* nrep){
	char chemin_fichier[TAILLE_CHN];
	sprintf(chemin_fichier,"./%s/%s",nrep,nomfich);  // ON RECUPERE LE CHEMIN
	//printf("DEBUG: CMD: %s\n", chemin_fichier);
	s.n = taille(chemin_fichier)+1;
	//printf("> Taille: %d\n",s.n);
	s.t = malloc(s.n * sizeof(char));
	FILE *F;
	F = fopen(chemin_fichier,"r");
	int j=1;  
	char c;
	while((c=fgetc(F))!=EOF){
		s.t[j]=c;
		j++;
	}
	fclose(F);
	return s;
}

seq *stockage_seq(char *nrep){
	struct noms_sequences f;
	seq *s;
	//-----
	f = nom_nb(nrep);
	/*int j;
	for(j=0; j<f.n; j++){        // AFFICHAGE DES NOMS DE FICHIERS SI ON LE VEUT
		printf("%s\n",f.nom[j]);
	}*/    
	printf("\n");
	s = malloc(f.n * sizeof(seq));
	int i;
	for(i=0; i<f.n; i++){
		s[i] = creer(i);
		s[i] = lecture(s[i], f.nom[i], nrep);
	}
	return s;
}

void afficher(seq s){
	printf("\nLa sequence : ");
	int i;
	for(i=1;i<=s.n;i++){
		printf("%c",s.t[i]);
	}
}
