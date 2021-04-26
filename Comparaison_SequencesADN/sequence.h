
struct noms_sequences{ //pour recuperer les noms de fichier (chemin vers fichier)
	char **nom;
	int n;//nombre de fichier
};

struct SEQUENCE {
	int id;
	int n;  //taille de la sequence
	char *t; // la sequence 
};

typedef struct SEQUENCE seq;
 
 
seq creer(int id);
seq lecture(seq s,char*,char*);
void afficher(seq s);
float calcul_distance_2(seq s1,seq s2);
struct noms_sequences nom_nb(char* nrep);
seq *stockage_seq(char* nrep);
int nombre_fichiers(char *nrep);
