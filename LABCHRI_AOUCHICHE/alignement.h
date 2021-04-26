#include "famille.h"
#define TAILLE_SEQ 24

struct alignement{
	seq* align; // tableau de sequences 
	int nb_seq; //nombre element dans 1 seul alignement
	char *sequence_cons; // notre sequence consensus resultante
};
typedef struct alignement alignement;

alignement* alignement_intial(seq *tab_seq, famille f_seq);
char* alignement_sequence(seq seq1,seq seq2);
alignement* alignement_final(alignement *align_init,int nb_f);
char *sequence_consensus(alignement al);
void affiche_alignement(alignement *al,int nb_f);
