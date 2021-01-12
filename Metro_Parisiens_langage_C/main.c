#include "lecture.h"


void viderBuffer();
int lire(char *chaine, int longueur);
long lireLong();



int main(){

	GRAPHE G;
	G=remplir_graphe();
	//afficher_graphe(G);
	char *STATION = malloc(100*sizeof(char));
	//char str[3];
	int bol,nb_sta;
	int num_sta ;
	int *tab;
	int bol1=1;
	DIJKSTRA D ;
	printf("\n");
	printf("\033[31m");
	printf("\n\n\n");
	printf("********Binvenue dans le METRO PARISIEN********");
	printf("\033[00m\n");

	printf("\n\n\n");

	int tab_stat[ 2 ] ;
	int exist = 1 ;

	while(bol1){
		for(int i = 0 ; i < 2 ; i ++){ // 2 est le nombre de sommets dont on a besoin
			do {
				exist = 1;
				if(i== 0 )
					printf("Entrez le nom de station de départ :\n");
				else if(i==1)
					printf("Entrez le nom de station d'arrivé :\n");

				//gets(STATION);
				lire(STATION , 100);
				nb_sta=chercher_num_station(G,STATION,&num_sta);
				
				if(nb_sta == 0){
					printf("La gare que vous avez saisi n'existe pas !\n");
					exist = 0 ;
				}
			}while (exist != 1 );

				if(nb_sta == 1){ 
					tab_stat[i] = num_sta ;
				}
				else{
					printf("choisissez un numéro correspondant a votre métro préféré :\n");
					tab=malloc(nb_sta * sizeof(int));
					for(int j=0;j<nb_sta;j++){
						tab[j]=num_sta;
						if((G.tab_sommets[tab[j]].num_metro == 30) || (G.tab_sommets[tab[j]].num_metro == 70) ){
							printf("%d(%dbis) | ",G.tab_sommets[tab[j]].num_metro , G.tab_sommets[tab[j]].num_metro/10);
						}
						else	
							printf("%d | ",G.tab_sommets[tab[j]].num_metro);
						
						num_sta++;
					}
					printf("\n");
					bol=1;
					int temp ;
					while(bol){
						int b = lireLong();
						//gets(str);
						temp = (int) b ;//atoi(str);
						for(int j=0;j<nb_sta;j++){
							if(G.tab_sommets[tab[j]].num_metro == temp ){
							 bol=0;
							 tab_stat[i] = tab[j] ;
							}
						}
						if(bol == 1) printf("vous avez saisi un numéro incorrecte, ressayez !\n ");
					}
					free(tab);
				
				}
		}			
					
						D = court_chemin(G ,tab_stat[0],tab_stat[1]);
						affichage_trajet(D,G);
					
			printf("\n");
			printf("********************************************\n");
			printf("Voulez quitter l'application ?\n0 pour Quitter.\n1 pour Continuer .\n");
			printf("Saisissez : ");
			long a = lireLong();
			//gets(str);
			bol1=(int) a;
			printf("********************************************\n");
			if(bol1 == 0) printf("Au revoir !\n");
		

	}
	
	free(STATION);
	//free(tab);
	graphe_liberer(G);
	dijkstra_liberer(D);
	exit(0);
}






void viderBuffer()
{
    int c = 0;
    while (c != '\n' && c != EOF)
    {
        c = getchar();
    }
}
 
int lire(char *chaine, int longueur)
{
    char *positionEntree = NULL;
 
    if (fgets(chaine, longueur, stdin) != NULL)
    {
        positionEntree = strchr(chaine, '\n');
        if (positionEntree != NULL)
        {
            *positionEntree = '\0';
        }
        else
        {
            viderBuffer();
        }
        return 1;
    }
    else
    {
        viderBuffer();
        return 0;
    }
}

long lireLong()
{
    char nombreTexte[100] = {0}; // 100 cases devraient suffire
 
    if (lire(nombreTexte, 100))
    {
        // Si lecture du texte ok, convertir le nombre en long et le retourner
        return strtol(nombreTexte, NULL, 10);
    }
    else
    {
        // Si problème de lecture, renvoyer 0
        return 0;
    }
}