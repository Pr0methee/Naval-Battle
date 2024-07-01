#ifndef _ADDER_H_
#define _ADDER_H_
#include <conio.h>
#include "asker.h"
#include "verif.h"
#include "affichage.h"


struct grille add(int l,std::string nom,struct grille array){
    bool valid = false;
    int x,y;
    char v[] = {'V','H'};
    struct position p;
    char orient;


    while (!valid){
        affiche_grille(array);
        std::cout << "You're going to add a '" << nom << "' it has a length of " << l << "\n";

        p = ask_case("Give the identifier of the first case : ");
        x = p.pos[0];
        y = p.pos[1];

        orient = ask_value("The orient of the boat (V/H) :",v);

        if (!verif(l,x,y,orient,array)){
            std::cout << "Error : some values you entered lead to an incorrect position. Press any key to continue\n";
            _getch();
            system("cls");
        }
        else{
            valid=true;
        }
    }

    for (int i=0;i<l;i++){
        array.arr[y][x] = l;
        if (orient=='V'){
            y+=1;
        }
        else{
            x+=1;
        }
    }
    return array;
}


struct grille random_add(int l,struct grille array){
    bool valid = false;
    int x,y;
    char v[] = {'V','H'};
    char orient;

    while (!valid){
        x = rand()%N;
        y = rand()%N;
        orient = v[rand()%2];
        valid = verif(l,x,y,orient,array);
    }

    for (int i=0;i<l;i++){
        array.arr[y][x] = l;
        if (orient=='V'){
            y+=1;
        }
        else{
            x+=1;
        }
    }
    return array;
}

#endif