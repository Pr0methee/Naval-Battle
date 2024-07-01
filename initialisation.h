#ifndef _INITIALISATION_H_
#define _INITIALISATION_H_
#include "structures.h"
#include "adder.h"

//Fonction d'initialisation :
struct flotte init_flotte(){
    struct flotte flotte;
    flotte.l[0].l=5;
    flotte.l[0].nom="porte-avion";
    flotte.l[1].l=4;
    flotte.l[1].nom="croiseur";
    flotte.l[2].l=3;
    flotte.l[2].nom="contre-torpilleur";
    flotte.l[3].l=3;
    flotte.l[3].nom="contre-torpilleur";
    flotte.l[4].l=2;
    flotte.l[4].nom="torpilleur";
    return flotte;
}

struct grille init_vide(){
    struct grille arr;
    for (int i=0;i<N;i++){
        for (int j=0;j<N;j++){
            arr.arr[i][j]=0;
        }
    }
    return arr;
}


struct grille init(){
    struct grille array = init_vide();
    struct flotte flotte = init_flotte();

    for (int i=0;i<5;i++){
        system("cls");
        array = add(flotte.l[i].l,flotte.l[i].nom,array);
    }
    system("cls");
    return array;
}
//--------------------------

#endif