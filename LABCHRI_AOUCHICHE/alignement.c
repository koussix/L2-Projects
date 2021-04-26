#include <stdio.h>
#include <stdlib.h>
#include "alignement.h"
#include <string.h>

alignement* alignement_intial(seq *tab_seq, famille f_seq){
	famille g=f_seq;   //g est un pointeur qui pointe sur la tete de liste..
	int nb= nb_famille(f_seq);
	alignement *al;
	al=malloc(nb*sizeof(alignement));
		if(!al) exit(4);
	int nb_elem;
	for(int i=0;i<nb;i++){
		nb_elem= g->nb_elem;
		al[i].sequence_cons=NULL; // ici on ne s'interesse pas encore a la seq consensus
		al[i].align=malloc(nb_elem*sizeof(seq)); //on alloue taille de seq
		if(!al[i].align) exit(5);
		al[i].nb_seq=nb_elem;
		for( int j=0; j<nb_elem ;j++){
			
			al[i].align[j].t=malloc(TAILLE_SEQ*sizeof(char)); //on aloue notre chaine de caractere correspondant a notre sequence
			al[i].align[j].id = tab_seq[g->id[j]].id;	 // on recupére notre identifiant
			al[i].align[j].n = tab_seq[g->id[j]].n;		// on recupére notre vrai taille != TAILLE_SEQ(majoré)

			for ( int k=1 ;k<=TAILLE_SEQ ; k++){
				if (k< tab_seq[g->id[j]].n){
					al[i].align[j].t[k]=tab_seq[g->id[j]].t[k];
				}
				else 
					{al[i].align[j].t[k]='-';}
			}
			//printf(" la seq %d est %s \n",g->id[j], al[i].align[j].t);
		}
		g=g->suiv;
	}
	return al;
}

char* deplacer_tiret(char *ch1){ //comme on fait le parcours de notre tablea distance2 en sens inverse on se retrouve avec des tirets
									// supplémentaire au début(sensés etre a la fin) resultant de la TAILLE_SEQ fixé qui est >= taille_seq
	int nb_espaces=0;
	int i=1;
	while( i<TAILLE_SEQ && ch1[i]=='-'){
		nb_espaces++;
		i++;
	}
	char* ch2=malloc(TAILLE_SEQ*sizeof(char));
	int j=1;
	while(i<TAILLE_SEQ){
		ch2[j]=ch1[i];
		i++; j++;
	}
	while(j<TAILLE_SEQ){
		ch2[j]='-';
		j++;
	}
	return ch2;
}

char* alignement_sequence(seq s1,seq s2){ // 2 ETAPES :
	// 1. ETAPE CALCUL DE LA DISTANCE 2
	int n=(s1.n);
	int m=(s2.n);
	float tab[n][m];
	int i=0;
	int j=0;
	for(i=0;i<n;i++){
		for(j=0;j<m;j++){
			if(i==0){
				tab[i][j]=j*1.5;}
			else if(j==0){
				tab[i][j]=i*1.5;}
			else {
			float f1=tab[i-1][j-1]+compare_carac(s1.t[i],s2.t[j]);
			float f2=tab[i-1][j]+1.5;
			float f3=tab[i][j-1]+1.5;
			tab[i][j]=min(f1,f2,f3);
			}
	}
}
	
	float case_mat;
	// ETAPE 2 REMONTER LA MATRICE DISTANCE 2 POUR RETROUVER L'ALIGNEMENT
	char *seq1;
	seq1=malloc(TAILLE_SEQ*sizeof(char));
		if(!seq1) exit(6);
	char *seq2;
	seq2=malloc(TAILLE_SEQ*sizeof(char));  // declaration de 2seq temporaires qui vont recevoir l'alignement au fur et a mesure du parcours de notre table
		if(!seq2) exit(7);
	for(int k=1; k<=TAILLE_SEQ;k++){
		seq1[k]='-';
		seq2[k]='-';
	}  
	case_mat= tab[n-1][m-1];
	i=n-1; 
	j=m-1;
	int k=TAILLE_SEQ-1;
	int l=TAILLE_SEQ-1;
	
	while ( i>0 && j>0 ) { // cas d'arret i> 0 j> 0 (inversement au calcul de distance )
		case_mat= tab[i][j];

		if(case_mat == (compare_carac(s1.t[i],s2.t[j]) + tab[i-1][j-1])){ //cas ou aucune isertion n'a été fait
			seq1[k] = s1.t[i]; 
			seq2[l] = s2.t[j];	
			i--;	k--;
			j--;	l--;
			
		}
		else if(case_mat == ( tab[i-1][j] + 1.5 ) ){ // cas d'une insertion de tiret dans seq2
			seq1[k] = s1.t[i]; 
			seq2[l] = '-';		
			k=k-1;	l=l-1;
			i=i-1;
		}
		else if(case_mat == ( tab[i][j-1] + 1.5 ) ){ // cas d'une insertion de tiret dans seq1
			seq1[k] = '-';		
			seq2[l] = s2.t[j];	
			j=j-1;
			k=k-1;	l=l-1;
			}
	}
	while(i>0){ // si on sort de la boucle alors que i>0 il faut continuer les insertion..
		seq1[k]= s1.t[i]; i--; k--;
	}
	while(j>0){
		seq2[l]= s2.t[j]; j--; l--;
	}
	
	for(k=1; k<TAILLE_SEQ;k++){ // on recupére la seq2 dans s2.t qui correspont a notre variable passé en argument
		s2.t[k]=seq2[k];
	}
	s2.t=deplacer_tiret(s2.t);
	return s2.t;
}

char calcul_freq(int i,alignement al){
	int n=5;
	int freq_ap[n]; //frequence appartition d'une lettre
	int j;
	for(j=0;j<5;j++){
		freq_ap[j]=0;}
	j=0;
	while(j<al.nb_seq){
		switch(al.align[j].t[i]){
		case 'A' : freq_ap[0]++; break;
		case 'C' : freq_ap[1]++; break;
		case 'G' : freq_ap[2]++; break;
		case 'T' : freq_ap[3]++; break;
		case '-' : freq_ap[4]++; break;
		}
		j++;
	}
	int max=0; int pos=-1;
	int bool=0;	 //le booleen nous servira a savoir (cas =0 -> il ya un max , cas =1 -> pas de max(insertion du .) ) 
	for(j=0;j<n;j++){ 	 	// on ramene le maximum et la position du max 
		if(freq_ap[j]>max) {
			pos=j;
			max=freq_ap[j];}
	}
	for(j=0;j<n;j++){ // on verifie qu'il n'y a pas d'autre lettre qui se repete autant de fois que le max .. sinon bool=1
		if((freq_ap[j]>=max)&&(j!=pos)){
			bool=1;
		}
	}
	
	if(bool==1) return '.'; //cas ou il n y'a pas de maximum distingué 
	switch(pos){ // il ya un maximum on utilise notre petite fonction de hachage pour retrouver la lettre
		case 0 : return 'A';
		case 1 : return 'C';
		case 2 : return 'G';
		case 3 : return 'T';
		case 4 : return '-';
		}
	return '.';
}

char *sequence_consensus(alignement al){
	char *c=malloc(TAILLE_SEQ*sizeof(char));
		if(!c) exit(8);
	for(int i=1;i<=TAILLE_SEQ;i++){
		c[i]=calcul_freq(i,al);
	}
return c;
}

alignement* alignement_final(alignement *align_init,int nb_f){

	for(int i=0;i<nb_f;i++){ // on retrouve nos sequence consensus
		for(int j=1; j<align_init[i].nb_seq;j++){
			align_init[i].align[j].t=alignement_sequence(align_init[i].align[0],align_init[i].align[j]);
		}
		align_init[i].sequence_cons=sequence_consensus(align_init[i]);
		
	}
	
	return align_init;
}

void affiche_alignement(alignement *al,int nb_f){
	for(int i=0;i<nb_f;i++){
		printf("Allignement num %d\n",i);
		for(int j=0;j<al[i].nb_seq;j++){
			printf("id => %2d || sequence : ",al[i].align[j].id); 
			for( int k=1;k<TAILLE_SEQ;k++){
				printf("%c",al[i].align[j].t[k]);
			}
			printf("\n");
		}
		printf("SEQ consensus   ==>    ");
		for(int l=1; l<TAILLE_SEQ;l++){
			printf("%c",al[i].sequence_cons[l]);
		}
		printf("\n\n");
	}
	
}
