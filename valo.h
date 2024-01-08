#ifndef VALORANT_H_INCLUDED
#define VALORANT_H_INCLUDED

//  Ichsanul Hakim
//  Aimanul Shidqi N

// ---- Library --- //
#include <iostream>
#include <ctime>
using namespace std;

// Define Pointer
#define info(P) P->info
#define next(P) P->next
#define nextWea(P) P->nextWea
#define nextRel(P) P->nextRel
#define first(R) (R).first

//===========================//

struct Senjata{
    string namaSenjata;
    string damage;
    string fireRate;
    string price;
    string type;
};

typedef Senjata infotypeSenjata;

typedef struct Weapon *adrWeapon;
struct Weapon{
    infotypeSenjata info;
    adrWeapon next;
};

struct listWeapon{
    adrWeapon first;
};

//===========================//

typedef struct relation *adrRelation;
struct relation{
    adrWeapon nextWea;
    adrRelation next;

};

//===========================//

struct Pemain{
    int idPemain;
    string namaPemain;
    string tier;
};

typedef Pemain infotypePemain;

typedef struct Player *adrPlayer;
struct Player{
    infotypePemain info;
    adrPlayer next;
    adrRelation nextRel;
};

struct listPlayer{
    adrPlayer first;
};

// ============================ //

void createListPlayer(listPlayer &L);
adrPlayer newElmPlayer(infotypePemain x);
void insertLastPlayer(listPlayer &L, infotypePemain x);
adrPlayer searchPlayer(listPlayer L, infotypePemain x);
void showSearchPlayer(listPlayer L, infotypePemain x);
void showAllPlayer(listPlayer L);
void deleteFirstPlayer(listPlayer &L, adrPlayer P);
void deleteLastPlayer(listPlayer &L, adrPlayer P);
void deleteAfterPlayer(listPlayer &L, adrPlayer Prec, adrPlayer P);

// ============================ //

void createListWeapon(listWeapon &L);
adrWeapon newElmWeapon(infotypeSenjata x);
void insertLastWeapon(listWeapon &L, infotypeSenjata x);
adrWeapon searchWeapon(listWeapon L, infotypeSenjata x);
void showSearchWeapon(listWeapon L, infotypeSenjata x);
void showAllWeapon(listWeapon L);
void deleteFirstWeapon(listWeapon &L, adrWeapon P);

//=============================//

adrRelation newRelation();
void insertRelation(adrPlayer &P, adrWeapon B);
void showAllRelation(listPlayer LP);

//=============================//
void searchUsedItems(listPlayer LP, infotypePemain x);
void countUsedItems(listPlayer LP, infotypePemain x);
void deleteAllRelation(listPlayer LP, adrRelation &P, infotypePemain x);
void deleteAllData(listPlayer &LP, listWeapon &LB, infotypePemain x);
int selectionMenu();


#endif // VALORANT_H_INCLUDED
