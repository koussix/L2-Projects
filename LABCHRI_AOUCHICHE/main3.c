#include <stdio.h>
#include <stdlib.h>
#include "alignement.h"

int main(int argc, char** argv){
printf("azul dans le prog\n");
dis d2;
d2=distance_2(argv[1]);
seq *tab_seq=stockage_seq(argv[1]);
Tri_d *tab=NULL;
tab=copie_trie(d2,tab);
famille f=NULL;
f=crea_famille(f,tab,tab_seq);
int nb_f=nb_famille(f);
alignement *al=alignement_intial(tab_seq,f);
al=alignement_final(al,nb_f);
affiche_alignement(al,nb_f);

printf("azul dans le prog\n");
/* //un test de notre alignement
printf( " ON TEST NOS SEQUENCES \n");

al[4].align[2].t=alignement_sequence(al[1].align[0],al[4].align[2]);
al[1].align[0].t=alignement_sequence(al[4].align[2],al[1].align[0]);

printf("\n");
printf("dans le main\n");

for(int i=1; i<TAILLE_SEQ ;i++)
printf("%c",al[1].align[0].t[i]);
printf("\n");
for(int i=1; i<TAILLE_SEQ ;i++)
printf("%c",al[4].align[2].t[i]);
*/

exit(0);
}
