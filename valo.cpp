#include "valo.h"

void createListPlayer(listPlayer &L){
    first(L) = NULL;
}

adrPlayer newElmPlayer(infotype x){
    adrPlayer P = new player;
    info(P) = x;
    next(P) = NULL;
    childNext(P) = NULL;
    return P;
}

adrPlayer searchPlayer(listPlayer L, infotype x){
    adrPlayer P = first(L);
    while(next(P) != NULL && info(P) != x){
        P = next(P);
    }
    if(info(P) == x){
        return P;
    }else{
        return NULL;
    }
}

void showPlayer(listPlayer L, infotype x){
    adrPlayer P = searchPlayer(L, x);
    if(P != NULL){
        cout << info(P) << endl;
    }else{

    }
}

void showAllPlayer(listPlayer L){

}
