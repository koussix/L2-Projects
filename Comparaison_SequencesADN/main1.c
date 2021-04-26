#include <stdio.h>
#include <stdlib.h>
#include "sequence.h"
#include "distance.h"

int main(int argc, char** argv){

dis d2; // DE TYPE DISTANCE
d2=distance_2(argv[1]);
//affiche_dis(d2);  // si on veut afficher notre tableau non trié
seq *tab_seq=NULL;
tab_seq=stockage_seq(argv[1]);
Tri_d *tab=NULL;
tab=copie_trie(d2,tab);
affiche_distance_trier(tab); // ON AFFICHE EN MEME TEMPS LE TABLEAU TRIÉ RESULTANT DES CALCUL DES D2 DANS CETTE FONCTION

//dis d1;
//d1=distance_1(argv[1]);
//affiche_dis(d1);

exit(0);
}
