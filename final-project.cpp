#include <iostream>
#include <fstream>
#include <limits>
using namespace std;

const int maxrow = 100;

string arID[maxrow] = {};
string arBarang[maxrow] = {};
string arKuantitas[maxrow] = {};

void tambahBarang(){
    char id[5];
    char barang[50];
    char kuantitas[99];

    cin.ignore();
    cout << "Masukkan ID Barang: ";
    cin.getline(id, 5);
    cout << "Masukkan Nama Barang: ";
    cin.getline(barang, 50);
    cout << "Masukkan Kuantitas Barang: ";
    cin.getline(kuantitas, 99);
    
    for(int i = 0; i < maxrow; i++){
        if (arID[i] == "\0")
        {
            arID[i] = id;
            arBarang[i] = barang;
            arKuantitas[i] = kuantitas;
            break;
        }
        
    }

}

void tambahKuantitas(){

}

void kurangKuantitas(){

}

void listBarang(){
    int hitung = 0;

        cout << " ____________________________________________" << endl;
        cout << "| NO |          LIST DATA BARANG             |"<< endl;
        cout << "|    |_______________________________________|" << endl;
        cout << "|    |     ID    | NAMA BARANG  | KUANTITAS  |" << endl;
        cout << "|____|___________|______________|____________|" << endl;

         for(int i = 0; i < maxrow; i++){
            if (arID[i] != "\0")
            {
                hitung++;
                cout << "|  " << hitung << " |" << arID[i] << "          |" << arBarang[i] << "             |" << arKuantitas[i] << "           |" << endl;
            }
        }

        if (hitung == 0)
        {
            cout << "Data Kosong" << endl;
        }
        
}

void edit(){

}

void hapus(){

}

void saveData(){
    ofstream myFile;
    myFile.open("dataBarang.txt");
}

void handleNumber(int number){
    while (true)
    {
        if (cin.fail())
        {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(),'\n');   
        }
    }
}

int main(){
    string id;
    int pilih;

    cout << "=============================================" << endl;
    cout << "             INVENTORY MANAGEMENT            " << endl;
    cout << "=============================================" << endl;
    cout << "-----------------GUDANG BARANG---------------" << endl; 
    cout << "_____________________________________________" << endl;
    cout << "~~~~~~~~~~~ SELAMAT DATANG DI TOKO ~~~~~~~~~~" << endl;
    cout << "~~~~~~~~~~~ LIST PRODUK DAN HARGA  ~~~~~~~~~~" << endl;
    cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;

    do
    {
        cout << " ____________________________________________" << endl;
        cout << "| NO |              PILIHAN                  |"<< endl;
        cout << "|____|_______________________________________|" << endl;
        cout << "| 1  |  TAMBAH BARANG                        |"<< endl;
        cout << "| 2  |  TAMBAH KUANTITAS                     |"<< endl;
        cout << "| 3  |  KURANG KUANTITAS                     |"<< endl;
        cout << "| 4  |  EDIT BARANG                          |"<< endl;
        cout << "| 5  |  LIST BARANG                          |"<< endl;
        cout << "| 6  |  CARI BARANG                          |"<< endl;
        cout << "| 7  |  HAPUS BARANG                         |"<< endl;
        cout << "| 8  |  EXIT & SAVE                          |"<< endl;
        cout << "|____|_______________________________________|" << endl;
        cout << "| MASUKKAN PILIHAN ANDA: ";
        cin >> pilih;

        switch (pilih)
        {
        case 1:
            tambahBarang();
            break;
        case 2:
            
            break;
        case 3:

            break;

        case 4:

            break;

        case 5:
            listBarang();
            break;
        }
        } while (pilih != 6);


    
    
}