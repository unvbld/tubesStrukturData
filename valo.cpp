#include "valo.h"

using namespace std;

void createListPlayer(listPlayer &L){
    first(L) = NULL;
}

adrPlayer newElmPlayer(infotypePemain x){
    adrPlayer P = new Player;
    info(P) = x;
    next(P) = NULL;
    nextRel(P) = NULL;
    return P;
}

void insertLastPlayer(listPlayer &L, infotypePemain x){
    adrPlayer P = newElmPlayer(x);
    adrPlayer Q = first(L);
    if(first(L) == NULL){
        first(L) = P;
    }else{
        while(next(Q) != NULL){
            Q = next(Q);
        }
        next(Q) = P;
    }
}

adrPlayer searchPlayer(listPlayer L, infotypePemain x){
    adrPlayer P = first(L);
    while(next(P) != NULL && info(P).idPemain != x.idPemain){
        P = next(P);
    }
    if(info(P).idPemain == x.idPemain){
        return P;
    }else{
        return NULL;
    }
}

void showSearchPlayer(listPlayer L, infotypePemain x){
    adrPlayer P = searchPlayer(L, x);
    if(P != NULL){
        cout <<"Pemain dengan id "<< info(P).idPemain << " ditemukan"<< endl;
    }else{
        cout <<"Pemain dengan id"<<x.idPemain <<" tidak ditemukan"<< endl;
    }
}

void showAllPlayer(listPlayer L){
    adrPlayer P = first(L);
    int i = 1;
    cout<<"DATA PLAYER"<<endl;
    while(P != NULL){
        cout<< "ID : "<<info(P).idPemain<<endl;
        cout<< "Nama : "<<info(P).namaPemain<<endl;
        cout << "Tier : "<<info(P).tier<< endl;
        P = next(P);
        i++;
    }
}

void deleteFirstPlayer(listPlayer &L, adrPlayer P){
    adrPlayer Q = first(L);
    if(first(L) == NULL){
        cout<<"`Tidak ada player`"<<endl;
    }else if(next(Q) == NULL){
        P = first(L);
        first(L) = NULL;
    }else{
        P = first(L);
        first(L) = next(P);
        next(P) = NULL;
    }
}

void deleteLastPlayer(listPlayer &L, adrPlayer P){
    if(first(L) == NULL){
        cout<<"`Tidak ada Player`"<<endl;
    }else{
        adrPlayer Q = first(L);
        while(next(Q) != P){
            Q = next(Q);
        }
        next(Q) = NULL;
    }
}

void deleteAfterPlayer(listPlayer &L, adrPlayer Prec, adrPlayer P){
    if(first(L) == NULL){
        cout<<"`Tidak ada Player`"<<endl;
    }else{
        Prec = first(L);
        while(next(Prec) != P){
            Prec = next(Prec);
        }
        next(Prec) = next(P);
        next(P) = NULL;
    }
}

//=================================//


void createListWeapon(listWeapon &L){
    first(L) = NULL;
}

adrWeapon newElmWeapon(infotypeSenjata x){
    adrWeapon P = new Weapon;
    info(P) = x;
    next(P) = NULL;
    return P;
}

void insertLastWeapon(listWeapon &L, infotypeSenjata x){
    adrWeapon P = newElmWeapon(x);
    adrWeapon Q = first(L);
    if(first(L) == NULL){
        first(L) = P;
    }else{
        while(next(Q) != NULL){
            Q = next(Q);
        }
        next(Q) = P;
    }
}

adrWeapon searchWeapon(listWeapon L, infotypeSenjata x){
    adrWeapon P = first(L);
    while(next(P) != NULL && info(P).namaSenjata != x.namaSenjata){
        P = next(P);
    }
    if(info(P).namaSenjata == x.namaSenjata){
        return P;
    }else{
        return NULL;
    }
}

void showSearchWeapon(listWeapon L, infotypeSenjata x){
    adrWeapon P = searchWeapon(L, x);
    if(P != NULL){
        cout<<"Senjata dengan nama "<<info(P).namaSenjata<<" ditemukan`"<<endl;
    }else{
        cout<<"`Senjata "<<x.namaSenjata<<" tidak ditemukan`"<<endl;
    }
}

void showAllWeapon(listWeapon L){
    adrWeapon P = first(L);
    int i = 1;
    cout<<"=======DATA Senjata======="<<endl;
    while(P != NULL){
        cout<< "Nama Senjata :"<<info(P).namaSenjata<<endl;
        cout<< "Damage : " << info(P).damage<<endl;
        cout<< "Fire Rate : "<<info(P).fireRate<<endl;
        cout<< "Harga Senjata : " <<info(P).price<<endl;
        cout<< "Tipe Senjata : "<<info(P).type<<endl;
        P = next(P);
        i++;
    }
    cout<<"========================="<<endl;
}

void deleteFirstWeapon(listWeapon &L, adrWeapon P){
    adrWeapon Q = first(L);
    if(first(L) == NULL){
        cout<<"`Tidak ada Senjata`"<<endl;
    }else if(next(Q) == NULL){
        P = first(L);
        first(L) = NULL;
    }else{
        P = first(L);
        first(L) = next(P);
        next(P) = NULL;
    }
}

adrRelation newRelation(){
    adrRelation P = new relation;
    nextWea(P) = NULL;
    next(P) = NULL;
    return P;
}

void insertRelation(adrPlayer &P, adrWeapon B){
    adrRelation R = newRelation();
    if(nextRel(P) == NULL){
        nextRel(P) = R;
        nextWea(R) = B;
    }else{
        adrRelation Q = nextRel(P);
        while(next(Q) != NULL){
            Q = next(Q);
        }
        next(Q) = R;
        nextWea(R) = B;
    }
}

void showAllRelation(listPlayer LP){
    cout<<"=======Senjata Yang Digunakan======="<<endl;
    if(first(LP) == NULL){
        cout<<"`Tidak ada orang yang menggunakan Senjata ini`"<<endl;
    }else{
        adrPlayer pP = first(LP);

        int i = 1;
        while(pP != NULL){
            cout<<i<<". No.ID: "<<info(pP).idPemain<<endl;
            cout<<"   Nama : "<<info(pP).namaPemain<<endl;
            adrRelation rP = nextRel(pP);
            while(rP != NULL){
                cout<<info(nextWea(rP)).namaSenjata<<endl;
                rP = next(rP);
            }
            i++;
            pP = next(pP);
            cout<<endl;
        }
    }
    cout<<"======================================"<<endl;
}

void searchUsedItems(listPlayer LP, infotypePemain x){
    adrPlayer pP = searchPlayer(LP, x);
    if(pP != NULL){
        int i = 1;
        adrRelation rP = nextRel(pP);
        cout<<"Senjata yang digunakan oleh "<<info(pP).namaPemain<<" dengan No.ID : "<<info(pP).idPemain<<": "<<endl;
        while(rP != NULL){
            cout<<i<<". "<<info(nextWea(rP)).namaSenjata<<endl;
            i++;
            rP = next(rP);
        }
    }else{
        cout<<"`Pemain yang ingin dicari senjata yang digunakannya tidak ditemukan`"<<endl;
    }
}

void countUsedItems(listPlayer LP, infotypePemain x){
    adrPlayer pP = searchPlayer(LP, x);
    if(pP != NULL){
        int i = 0;
        adrRelation rP = nextRel(pP);
        while(rP != NULL){
            i++;
            rP = next(rP);
        }
        cout<<"`Banyak senjata yang digunakan oleh "<<info(pP).namaPemain<<" dengan No.ID : "<<info(pP).idPemain<<": "<<i<<"`"<<endl;
    }else{
        cout<<"`Pemain yang ingin dihitung banyak senjata yang digunakannya tidak ditemukan`"<<endl;
    }
}

void deleteAllRelation(listPlayer LP, adrRelation &P, infotypePemain x){
    adrPlayer pP = searchPlayer(LP, x);;
    if(pP != NULL){
        adrRelation rP = nextRel(pP);
        if(rP == NULL){
            cout<<"`Pemain dengan No.ID: "<<info(pP).idPemain<<" tidak menggunakan senjata apapun`"<<endl;
        }else if(next(rP) == NULL){
            nextRel(pP) = NULL;
        }else{
            while(rP != NULL){
                P = rP;
                next(P) = NULL;
                rP = next(rP);
            }
            nextRel(pP) = NULL;
        }
        cout<<"`Semua senjata yang digunakan oleh "<<info(pP).namaPemain<<" dengan No.ID: "<<info(pP).idPemain<<" telah dihapus`"<<endl;
    }else{
        cout<<"`Pemain yang ingin dihapus semua relasinya tidak ditemukan`"<<endl;
    }
}

void deleteAllData(listPlayer &LP, listWeapon &LB, infotypePemain x){
    adrPlayer pP = searchPlayer(LP, x);
    if(pP != NULL){
        adrWeapon P, Prec;
        adrRelation rP = nextRel(pP);
        if(rP == NULL){
            cout<<"`Pemain dengan No.ID : "<<info(pP).idPemain<<" tidak memiliki relasi`"<<endl;
        }else{
            while(rP != NULL){
                P = nextWea(rP);
                deleteFirstWeapon(LB, P);
                rP = next(rP);
            }
        }
        adrRelation R;
        deleteAllRelation(LP, R, x);
        adrPlayer J, Grec;
        J = first(LP);
        while(next(J) != NULL){
            J = next(J);
        }
        if(pP == first(LP)){
            deleteFirstPlayer(LP, pP);
        }else if(pP == J){
            deleteLastPlayer(LP, pP);
        }else{
            deleteAfterPlayer(LP, Grec, pP);
        }
        cout<<"`Pemain dengan nama "<<info(pP).namaPemain<<" telah dihapus`"<<endl;
    }else{
        cout<<"`Pemain yang ingin dihapus semua datanya tidak ditemukan`"<<endl;
    }
}






int selectionMenu(){
    cout<<"================ INFORMATION ================"<<endl;
    cout<<"1. Insert Player Data"<<endl;
    cout<<"2. Insert Weapon Data"<<endl;
    cout<<"3. Add Used Weapon Data"<<endl;
    cout<<"4. Show All Pemain Data"<<endl;
    cout<<"5. Show All Weapon Data"<<endl;
    cout<<"6. Show All Pemain Data Along with The Weapon Used"<<endl;
    cout<<"7. Search and Show All Pemain Data"<<endl;
    cout<<"8. Search and Show All Weapon Data"<<endl;
    cout<<"9. Search and Display Weapon Data Used by Certain Players"<<endl;
    cout<<"10. Counts and Displays The Number of Weapons Used by a Particular Player"<<endl;
    cout<<"11. Delete All Relationships (Weapons) Used by Certain Players"<<endl;
    cout<<"12. Delete All Player Data "<<endl;
    cout<<"0. Finish"<< endl;
    cout<<"Pilih menu: ";
    int input = 0;
    cin>>input;
    return input;
}
