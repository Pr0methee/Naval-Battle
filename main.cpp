#include <iostream>
#include <cstdlib>
#include <ctime>
#include "adder.h"
#include "structures.h"
#include "initialisation.h"
#include "asker.h"

class Player{
    public:
    Player(): array(init()),tirs(init_vide()){}

    void show_everything(){
        system("cls");
        std::cout << "Your ships : \n";
        affiche_grille(array);
        std::cout << "\nPlaces you shot : \n";
        affiche_grille(tirs);
    }

    void play(grille o){
        position rep;
        do {rep = ask_case("Where do you want to try ? ");}while (tirs.arr[rep.pos[1]][rep.pos[0]] != 0);

        if (o.arr[rep.pos[1]][rep.pos[0]] == 0){
            tirs.arr[rep.pos[1]][rep.pos[0]]=-1;
            std::cout << "Oops... It seems that there is nothing here\n";
        }
        else{
            tirs.arr[rep.pos[1]][rep.pos[0]] = -2;
            std::cout << "Fantastic ! You found something !\n";
            c+=1;
        }
    }

    struct grille get_whole(){
        return array;
    }

    struct grille get_fire(){
        return tirs;
    }

    void set(grille o){
        array = o;
    }

    private:
    struct grille array;
    struct grille tirs;

    public:
    int c;
};


class Ordinateur{
    public:
    Ordinateur(){
        array = init_vide();
        tirs = init_vide();
        struct flotte flotte = init_flotte();
        for (int i=0;i<5;i++){
            array = random_add(flotte.l[i].l,array);
        }
    }

    struct grille get(){
        return array;
    }

    struct grille play(grille o){
        position rep;
        do {rep = random();}while (tirs.arr[rep.pos[1]][rep.pos[0]] != 0);

        std::cout << "Your opponent fired on " << coord_to_case(rep.pos[0],rep.pos[1])<<'\n';    
        if (o.arr[rep.pos[1]][rep.pos[0]] == 0){
            tirs.arr[rep.pos[1]][rep.pos[0]]=-1;
            std::cout << "You are lucky : your opponent didn't touch you.\n";
            o.arr[rep.pos[1]][rep.pos[0]] =-1;
        }
        else{
            tirs.arr[rep.pos[1]][rep.pos[0]] = -2;
            std::cout << "Ouch ! Your opponent touched one of your boats !\n";
            o.arr[rep.pos[1]][rep.pos[0]] = -2;
            c+=1;
        }

        return o;
    }


    private:
    struct grille array;
    struct grille tirs;

    public:
    int c;
};


class Partie{
    public:
    void show(){
        system("cls");
        p.show_everything();
    }

    void play(){
        int go = rand()%2;
        if (go == 1){
            std::cout << "You start\n";
            std::cout << "Press any keys to begin";
            _getch();
        }
        else{
            std::cout << "Your opponent starts\n";
            std::cout << "Press any keys to begin";
            _getch();
        }

        while (true){
            if (go==0){
                p.set(o.play(p.get_whole()));
                go=1;
                if (o.c == 17){
                    break;
                }
            }
            else{
                p.play(o.get());
                go=0;
                if (p.c == 17){
                    break;
                }
            }
            std::cout << "Press any keys to continue";
            _getch();
            show();
        }

        if (go==0){
            std::cout << "Fantastic, you won !";
        }
        else{
            std::cout << "What a sad day, you lose the game !";
        }
        std::cout << "Press any keys to continue";
        _getch();
    }

    private:
    Ordinateur o;
    Player p;
};



int main(){
    srand(time(0));
    Partie part;
    part.show();
    part.play();
    std::cout << "Press any keys to close";
    _getch();
    return 0;
}