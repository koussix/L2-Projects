#define Nb_fich 20
struct DISTANCE{ //nous renvoie une matrice de reel contenant les distance les dis entre les pairs de seq
	float **mat;
};
typedef struct DISTANCE dis;

struct Tri_distance{ //structure servant a reorganiser notre structure distance en la triant et en la transformant en tableau
	int id1,id2;		// contenant les identifiant de chaque seq en chaque case et un reel pour distinguer nos distances
	float reel;
};
typedef struct Tri_distance Tri_d;

dis creer_distance();
dis distance_1(char* nrep);
void affiche_dis(dis di);
dis distance_2(char* nrep);
Tri_d *copie_trie(dis d2,Tri_d *tab);
float min(float a,float b,float c);
void affiche_distance_trier(Tri_d *distance);
float compare_carac(char a,char b);
