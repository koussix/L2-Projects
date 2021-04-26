#define Nb_fich 20
#include "sequence.h"
#include "distance.h"
struct liste_famille{ // notre structure est une liste car on ne sait pas au préalable le nombre de famille à avoir
	int id[Nb_fich];
	int nb_elem; //nombre d'elem d'une famille
	struct liste_famille *suiv;
};
typedef struct liste_famille* famille;


int est_vide_famille(famille l);
famille ajouter_nouvelle_famille(famille l,int n);
famille inserer_dans_famille(famille l,int n);
famille crea_famille(famille f, Tri_d *d2,seq *tab_seq);
void affiche_famille(famille f,seq *tab_seq);
int nb_famille(famille f);
