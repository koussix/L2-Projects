# PROJET ALGO : METRO C'EST TROP

1. Présentation : 

    2. Le projet que nous avons réaliser à pour but de
        tiré part de l’algorithme de Dijkstra vu en cours
        et l’implémenter sur un problème réel qui est
        « La circulation des métro parisiens ».

    2. Nous avons donc pour ce fait programmer un
        code en C ayant pour but de stocker chaque
        sommet des différentes lignes de métro sous
        forme d’un graphe connexe, pour ensuite
        appliquer notre algorithme du plus court chemin
        afin de trouver la solution optimale.

1. Mise au point sur les différents fichier du projet:

    2. Metro.txt : contient la liste des différents sommets fournis et
        des arêtes, auxquels nous avant rajouté ces informations :
        Pour chaque sommet on associe un numéro de ligne.
        Si la station correspond à une des lignes ( 3bis ou 7bis ) on
        note ( 30 , 70 ) respectivement.
        Pour chaque arête on associe les deux terminus
        correspondant au trajet.
        Dans le cas d’un changement de ligne ( on est toujours
        dans la même station ) on insère deux terminus représentatif
        ( 1111 , 1111).

    2. Lecture.h: contient les signatures de fonctions utilisés dans
        le fichier lecture.c.

    2. Lecture.c : contient la partie du code qui se chargera de la
        lecture du fichier metro.txt et du remplissage du graphe.Graphe.h : contient les différentes structures
        manipulés dans notre conception du graphe (
        sommet, arc , graphe) en plus de la structure
        Dijkstra et une structure de liste ‘chemin’
        représentant notre plus court chemin. Contient
        aussi les signatures des fonctions manipulés dans
        graphe.c .

    2. Graphe.c : contient une liste de fonctions de
        manipulations de structures ( initialisation ,
        libération de mémoire , primitives d’utilisation
        d’une liste ...) et notre fonction clé du plus court
        chemin renvoyant notre structure Dijkstra
        rempli.


