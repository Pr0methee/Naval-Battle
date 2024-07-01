#ifndef _ASKER_H_
#define _ASKER_H_
#include <iostream>
#include "structures.h"

//Fonctions de demandes
struct position ask_case(std::string ch){
    std::string r,y;
    bool flag=false;
    int c[2];

    while (!flag){
        std::cout << ch;
        std::cin >> r;
        if (r.size()<2 || r.size()>3){
            continue;
        }
        if (!('A'<=r[0] && r[0]<='J')){
            continue;
        }
        c[0] = r[0]-'A';
        try{
            y = "";
            for (int i=1;i<r.size();i++){
                y += r[i];
            }
            c[1]=std::stoi(y)-1;
            flag=true;
        }
        catch (std::exception e){
            continue;
        }
    }
    struct position p ;
    p.pos[0] = c[0];
    p.pos[1] = c[1];
    return p;    
}

char ask_value(std::string ch , char* valid){
    if (sizeof(valid) == 0){
        throw new std::exception;
    }
    bool flag=false;
    std::string res;
    char r;
    while (!flag){
        std::cout << ch;
        std::cin >> res;
        if (res.size()==1){
            r=res[0];
            for (int i=0;i<sizeof(valid);i++){
                if (r==valid[i]){
                    return r;
                }
            }
        }
    }
    return ' ';
}

struct position random(){
    position p;
    p.pos[0] = rand()%N;
    p.pos[1] = rand()%N;
    return p;
}

//------------------------------------------------------------
#endif