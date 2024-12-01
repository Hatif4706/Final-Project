#include <iostream>
#include <fstream>
#include <limits>
using namespace std;

const int maxrow = 100;

string arID[maxrow] = {};
string arBarang[maxrow] = {};
string arKuantitas[maxrow] = {};
string arHarga[maxrow] = {};

void tambahBarang(){
    char id[5];
    char barang[50];
    char kuantitas[99];
    char harga[99];

    cin.ignore();
    cout << "Masukkan ID Barang: ";
    cin.getline(id, 5);
    cout << "Masukkan Nama Barang: ";
    cin.getline(barang, 50);
    cout << "Masukkan Kuantitas Barang: ";
    cin.getline(kuantitas, 99);
    cout << "Masukkan Harga Barang: ";
    cin.getline(harga, 99);
    
    for(int i = 0; i < maxrow; i++){
        if (arID[i] == "\0")
        {
            arID[i] = id;
            arBarang[i] = barang;
            arKuantitas[i] = kuantitas;
            arHarga[i] = harga;
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

        cout << " ________________________________________________________" << endl;
        cout << "| NO |                  LIST DATA BARANG                |"<< endl;
        cout << "|    |__________________________________________________|" << endl;
        cout << "|    |     ID    | NAMA BARANG  | KUANTITAS  |   HARGA  |" << endl;
        cout << "|____|___________|______________|____________|__________|" << endl;

         for(int i = 0; i < maxrow; i++){
            if (arID[i] != "\0")
            {
                hitung++;
                cout << "|  " << hitung << " |     " << arID[i] << "     |" << arBarang[i] << "             |" << arKuantitas[i] << "           |" << arHarga[i] << "         |"<< endl;
                
            }
        }

        if (hitung == 0)
        {
            cout << "Data Kosong" << endl;
        }
        
}

void cariBarang(string cari){
    int hitung = 0;

    cout << " ________________________________________________________" << endl;
    cout << "| NO |                  LIST DATA BARANG                |"<< endl;
    cout << "|    |__________________________________________________|" << endl;
    cout << "|    |     ID    | NAMA BARANG  | KUANTITAS  |   HARGA  |" << endl;
    cout << "|____|___________|______________|____________|__________|" << endl;

    for(int i = 0; i < maxrow; i++){
        if (arID[i] == cari){
            hitung++;
            cout << "|  " << hitung << " |     " << arID[i] << "     |" << arBarang[i] << "             |" << arKuantitas[i] << "           |" << arHarga[i] << "         |"<< endl;
            break;
        }
    }

    if(hitung == 0){
        cout << "Data Tidak Ditemukan" << endl;
    }

    cout << "|______________________________________________________|" << endl;
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
            cin.ignore();
            listBarang();
            break;
        case 6:
            cin.ignore();
            cout << "=============================================" << endl;
            cout << "|             CARI DATA BARANG              |" << endl;
            cout << "=============================================" << endl;
            cout << "Masukkan ID Barang: ";
            getline(cin, id);
            cariBarang(id);
            break;
        }
        } while (pilih != 8);


    
    
}