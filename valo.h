#ifndef VALORANT_H_INCLUDED
#define VALORANT_H_INCLUDED

//  Ichsanul Hakim
//  Aimanul Shidqi N

// ---- Library --- //
#include <iostream>
#include <ctime>

// Define Pointer
#define info(P) P->info
#define next(P) P->next
#define prev(P) P->prev
#define first(R) (R).first
#define last(R) (R).last

using namespace std;

// ---- Deklarasi Pointer adrPlayer --- //
typedef int *addressAgent;
typedef struct elmPlayer *adrPlayer;
typedef struct elmWeapon *adrWeapon;

// ----- Deklarasi Tipe Bentukan Infotype ----- //
struct infotypePlayer
{
    string idPlayer;
    string namaPlayer;
    string tier;
    string tanggal;
};

struct infotypeWeapon {
    string idWeapon;
    string namaWeapon;
    string damage;
    string fireRate;
    string price;
    string type;
};

// ------ Tipe Bentukan Element List ------ //

//Tipe bentukan Parent Player
struct elmPlayer
{
    infotypePlayer info;
    adrWeapon daftarWeapon;
    adrPlayer next;
    adrPlayer prev;
};

//Tipe bentukan Child Weapon
struct elmWeapon {
    infotypeWeapon info;
    adrWeapon next;
};

// ------ Tipe Bentukan List ----- //
struct listPlayer
{
    adrPlayer first;
    adrPlayer last;
};

struct listWeapon {
    adrWeapon first;
};

// ============================ //

void createListPlayer(listPlayer &L);
adrPlayer newElmPlayer(infotype x);
adrPlayer searchPlayer(listPlayer L, infotype x);
void showPlayer(listPlayer L, infotype x);
void showAllPlayer(listPlayer L);

// ============================ //

void createListWeapon(listWeapon &L);
adrPlayer newElmWeapon(infotype x);
adrPlayer searchWeapon(listWeapon L, infotype x);
void showWeapon(listWeapon L, infotype x);

#endif // VALORANT_H_INCLUDED
