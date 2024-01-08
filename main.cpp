#include "valo.h"

int main()
{
    //====================================//

    listPlayer LP;
    createListPlayer(LP);
    adrPlayer pP;
    infotypePemain dataPlayer;

    //====================================//

    listWeapon LB;
    createListWeapon(LB);
    adrWeapon bP;
    infotypeSenjata dataWeapon;

    //====================================//

    adrRelation rP;

    char YN;

    int input = selectionMenu();
    while(input != 0){
        switch(input){
        case 1:
            cout<<"Input No.ID Player: ";
            cin>>dataPlayer.idPemain;
            cout<<"Input Nama Player: ";
            cin>>dataPlayer.namaPemain;
            cout<<"Input Tier Player: ";
            cin>>dataPlayer.tier;
            insertLastPlayer(LP, dataPlayer);
            cout<<endl;
            break;
        case 2:
            cout<<"input nama Senjata : ";
            cin>>dataWeapon.namaSenjata;
            cout<<"input Damage Senjata : ";
            cin>>dataWeapon.damage;
            cout<<"input Fire Rate Senjata : ";
            cin>>dataWeapon.fireRate;
            cout<<"input Harga Senjata : ";
            cin>>dataWeapon.price;
            cout<<"input Type Senjata : ";
            cin>>dataWeapon.type;
            insertLastWeapon(LB, dataWeapon);
            cout<<endl;
            break;
        case 3:
            cout<<"No.ID Player: ";
            cin>>dataPlayer.idPemain;
            cout<<"Weapon yang digunakan: ";
            cin>>dataWeapon.namaSenjata;
            pP = searchPlayer(LP, dataPlayer);
            bP = searchWeapon(LB, dataWeapon);
            insertRelation(pP, bP);
            cout<<endl;
            break;
        case 4:
            cout<<endl;
            showAllPlayer(LP);
            cout<<endl;
            break;
        case 5:
            cout<<endl;
            showAllWeapon(LB);
            cout<<endl;
            break;
        case 6:
            cout<<endl;
            showAllRelation(LP);
            cout<<endl;
            break;
        case 7:
            cout<<"Masukkan No.ID pemain yang dicari: ";
            cin>>dataPlayer.idPemain;
            showSearchPlayer(LP, dataPlayer);
            cout<<"Berikut Data Keseluruhan Pemain"<<endl;
            showAllPlayer(LP);
            cout<<endl;
            break;
        case 8:
            cout<<"Masukkan nama Weapon yang dicari: ";
            cin>>dataWeapon.namaSenjata;
            showSearchWeapon(LB, dataWeapon);
            cout<<"Berikut Data Keseluruhan Senjata"<<endl;
            showAllWeapon(LB);
            cout<<endl;
            break;
        case 9:
            cout<<"Masukkan No.ID pemain yang ingin dicari data senjatanya: ";
            cin>>dataPlayer.idPemain;
            cout<<endl;
            searchUsedItems(LP, dataPlayer);
            cout<<endl;
            break;
        case 10:
            cout<<"Masukkan No.ID pemain yang ingin dihitung banyak senjatanya: ";
            cin>>dataPlayer.idPemain;
            cout<<endl;
            countUsedItems(LP, dataPlayer);
            cout<<endl;
            break;
        case 11:
            cout<<"Masukkan No.ID pemain yang ingin dihapus semua relasinya : ";
            cin>>dataPlayer.idPemain;
            cout<<endl;
            deleteAllRelation(LP, rP, dataPlayer);
            cout<<endl;
            break;
        case 12:
            cout<<"Masukkan No.ID pemain yang ingin dihapus semua datanya: ";
            cin>>dataPlayer.idPemain;
            cout<<endl;
            deleteAllData(LP, LB, dataPlayer);
            cout<<endl;
            break;
        }
        input = selectionMenu();
    }
    return 0;
}
