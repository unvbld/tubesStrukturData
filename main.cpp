#include <iostream>
#include "valo.h"

using namespace std;

int main() {
    int choice;
    do {
        cout << "=========================\n";
        cout << "||       MENU         ||\n";
        cout << "=========================\n";
        cout << "|| 1. Pilihan 1       ||\n";
        cout << "|| 2. Pilihan 2       ||\n";
        cout << "|| 3. Pilihan 3       ||\n";
        cout << "|| 4. Pilihan 4       ||\n";
        cout << "|| 5. Keluar          ||\n";
        cout << "=========================\n";
        cout << "Masukkan pilihan Anda: ";
        cin >> choice;

        switch(choice) {
            case 1:
                // Kode untuk pilihan 1
                cout << "Anda memilih opsi 1.\n";
                break;
            case 2:
                // Kode untuk pilihan 2
                cout << "Anda memilih opsi 2.\n";
                break;
            case 3:
                // Kode untuk pilihan 3
                cout << "Anda memilih opsi 3.\n";
                break;
            case 4:
                // Kode untuk pilihan 4
                cout << "Anda memilih opsi 4.\n";
                break;
            case 5:
                cout << "Terima kasih telah menggunakan program ini. Sampai jumpa!\n";
                break;
            default:
                cout << "Pilihan tidak valid. Silakan coba lagi.\n";
        }
    } while(choice != 5);

    return 0;
}
