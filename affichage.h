#ifndef _AFFICHAGE_H_
#define _AFFICHAGE_H_
#include <iostream>
#include "structures.h"

void affiche_grille(struct grille array){
    //anonce colonnes
    std::cout << "   ";
    for (int i=0;i<N;i++){
        std::cout << " " << char('A'+i) << "  ";
    }
    std::cout << "\n";

    //1ère ligne
    std::cout << "  \xC9";
    for (int i=0; i<N-1;i++){
        std::cout << "\xCD\xCD\xCD\xCB";
    }
    std::cout << "\xCD\xCD\xCD\xBB";
    std::cout << "\n";

    //cases suivantes
    for (int k=0;k<N-1;k++){
        if (k+1<10){std::cout << " ";}
        std::cout << k+1;
        for (int j=0;j<N;j++){
            std::cout << "\xBA";
            if (array.arr[k][j] == -1){
                std::cout << " "<< "O" <<" ";
            }
            else if (array.arr[k][j] == -2){
                std::cout << " "<< "x" <<" ";
            }
            else if (array.arr[k][j] != 0){
                std::cout << " "<< array.arr[k][j] <<" ";
            }
            else{
                std::cout << "   ";
            }
        }
        std::cout << "\xBA";
        std::cout << "\n";

        std::cout << "  \xCC";
        for (int j=0;j<N-1;j++){
            for (int i=0;i<3;i++){
                std::cout << "\xCD";
            }
            std::cout << "\xCE";
        }
        std::cout << "\xCD\xCD\xCD\xB9";
        std::cout << "\n";
    }
    std::cout << N;
    int k=N-1;
    for (int j=0;j<N;j++){
        std::cout << "\xBA";
        if (array.arr[k][j] == -1){
            std::cout << " "<< "O" <<" ";
        }
        else if (array.arr[k][j] == -2){
            std::cout << " "<< "x" <<" ";
        }
        else if (array.arr[k][j] != 0){
            std::cout << " "<< array.arr[k][j] <<" ";
        }
        else{
            std::cout << "   ";
        }
    }
    std::cout << "\xBA";
    std::cout << "\n";

    //dernière ligne
    std::cout << "  \xC8";
    for (int i=0; i<N-1;i++){
        std::cout << "\xCD\xCD\xCD\xCA";
    }
    std::cout << "\xCD\xCD\xCD\xBC";
    std::cout << "\n";
}

std::string coord_to_case(int x,int y){
    std::string r;
    r += char('A'+x);
    r += char('1'+y);
    return r;
}

#endif