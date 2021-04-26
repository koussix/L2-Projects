#include <stdio.h>
#include <stdlib.h>
#include "famille.h"

int main(int argc, char** argv){

dis d2;
d2=distance_2(argv[1]);

seq *tab_seq=stockage_seq(argv[1]);
Tri_d *tab=NULL;
tab=copie_trie(d2,tab);
famille f=NULL;
f=crea_famille(f,tab,tab_seq);
affiche_famille(f,tab_seq);

exit(0);
}
