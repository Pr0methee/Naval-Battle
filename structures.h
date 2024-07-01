#ifndef _TEST_H_
#define _TEST_H_
#define N 10
#include <string>

//Définitions des structures de base

//Grille du jeu (matrice NxN) (! bateaux dessus)
struct grille{
    int arr[N][N];
};

//Un bateau à un nom et une longueur
struct bateau{
    std::string nom;
    int l;
};

//Ensemble de bateaux
struct flotte{
    struct bateau l[5];
};

//Une case
struct position{
    int pos[2];
};

#endif