#include "util.h"


#ifndef __GRAPHE_H
#define __GRAPHE_H


struct sommet{
	int num_station; // identifiant du sommet 
	char nom_station[TAILLE_NOM]; // nom de la station
	int num_metro ;
};
typedef struct sommet SOMMET;

struct arc {
	int successeur_final ; // identifiant du succésseur finale
	int poid ; 

};
typedef struct arc ARC;

struct graphe {
	SOMMET *tab_sommets;
	ARC **tab_arc;
	int nb_sommets;
};
typedef struct graphe GRAPHE;

struct chemin{
	SOMMET station;
	struct chemin *suiv;
};
typedef struct chemin CHEMIN;

struct dijkstra{
	int id_debut ;
	int id_fin ;
	CHEMIN *plus_court; // le plus court chemin
	long int duree;
};
typedef struct dijkstra DIJKSTRA;

GRAPHE graphe_initialiser( int nb_sommets );
GRAPHE remplir_graphe();
int chercher_num_station(GRAPHE g,char *station,int *num_st);
void afficher_graphe(GRAPHE g);

CHEMIN *chemin_ajouter_sommet_deb(CHEMIN *l, SOMMET s);
void chemin_liberer ( CHEMIN *l );
void afficher_chemin( CHEMIN *l);

GRAPHE graphe_remplir(GRAPHE g);
void graphe_liberer(GRAPHE g);

DIJKSTRA court_chemin( GRAPHE g , int deb , int fin );
void dijkstra_liberer( DIJKSTRA d );

void affichage_trajet(DIJKSTRA D,GRAPHE G);
#endif
