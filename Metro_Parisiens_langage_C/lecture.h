#ifndef __LECTURE_H
#define __LECTURE_H

#include "util.h"

#include "graphe.h"

int nombre_sommets( char *nom_fichier );
GRAPHE lecture_sommet(char *fichier,GRAPHE g);
GRAPHE lecture_arcs(char *fichier,GRAPHE g); 


#endif
