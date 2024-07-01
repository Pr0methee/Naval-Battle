#ifndef _VERIF_H_
#define _VERIF_H_
#include "structures.h"

bool verif(int l,int x,int y, char orient, struct grille array){
    for (int i=0;i<l;i++){
        if (x >= N || y >= N){return false;}
        if (array.arr[y][x] !=0){return false;}
        if (array.arr[y-1][x] !=0 && y!=0){return false;}
        if (array.arr[y+1][x] !=0 && y != N-1){return false;}
        if (array.arr[y][x-1] !=0 && x!=0){return false;}
        if (array.arr[y][x+1] !=0 && x != N-1){return false;}
        
        if (orient=='V'){
            y+=1;
        }
        else{
            x+=1;
        }
    }
    return true;
}

#endif