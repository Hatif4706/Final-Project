#include <iostream>
#include <fstream>
#include <limits>
#include <iomanip>
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
        cout << "| NO |                    DATA BARANG                   |" << endl;
        cout << "|    |__________________________________________________|" << endl;
        cout << "|    |     ID    |   NAMA BARANG   | KUANTITAS |  HARGA |" << endl;
        cout << "|____|___________|_________________|___________|________|" << endl;

         for(int i = 0; i < maxrow; i++){
            if (arID[i] != "\0")
            {
                hitung++;
                cout << "|" << setw(2) << hitung 
                 << "  | " << setw(10) << arID[i] 
                 << "| " << setw(15) << arBarang[i] 
                 << " | " << setw(9) << arKuantitas[i] 
                 << " | " << setw(7) << arHarga[i] << "|" << endl;
                
            }
        }

        if (hitung == 0)
        {
           cout << "|                 TIDAK ADA DATA BARANG                 |" << endl;
        }

        cout << "|_______________________________________________________|" << endl;
        
}

void cariBarang(string cari){
    int hitung = 0;

        cout << " ________________________________________________________" << endl;
        cout << "| NO |                    DATA BARANG                   |" << endl;
        cout << "|    |__________________________________________________|" << endl;
        cout << "|    |     ID    |   NAMA BARANG   | KUANTITAS |  HARGA |" << endl;
        cout << "|____|___________|_________________|___________|________|" << endl;

    for(int i = 0; i < maxrow; i++){
        if (arID[i] == cari){
            hitung++;
            cout << "|" << setw(2) << hitung 
                 << "  | " << setw(10) << arID[i] 
                 << "| " << setw(15) << arBarang[i] 
                 << " | " << setw(9) << arKuantitas[i] 
                 << " | " << setw(7) << arHarga[i] << "|" << endl;
            break;
        }
    }

    if(hitung == 0){
        cout << "|                 TIDAK ADA DATA BARANG                 |" << endl;
    }

    cout << "|_______________________________________________________|" << endl;
}

void editBarang(string search){
    char id[5];
    char barang[50];
    char kuantitas[99];
    char harga[99];

    int pilihUpdate;
    int hitung = 0;


    for (int i = 0; i < maxrow; i++)
    {
        if(arID[i] == search){
            hitung++;
            cout << "Apa yang ingin kamu ubah?" << endl;
            cout << "1. Nama Barang" << endl;
            cout << "2. Kuantitas" << endl;
            cout << "3. Harga" << endl;
            cout << "Masukkan Pilihan: ";
            cin >> pilihUpdate;
            cin.ignore();

            switch (pilihUpdate)
            {
                case 1:
                    cout << "Masukkan Nama Barang Baru: "; 
                    cin.getline(barang, 50);
                    arBarang[i] = barang;
                    break;
            
                case 2:
                    cout << "Masukkan Kuantitas Barang Baru: ";
                    cin.getline(kuantitas, 99);
                    arKuantitas[i] = kuantitas;
                    break;

                case 3:
                    cout << "Masukkan Harga Barang Baru: ";
                    cin.getline(harga, 99);
                    arHarga[i] = harga;
                    break;
            
                default:
                    cout << "Pilihan tidak ada" << endl;
                    break;
            }

            cout << "Data berhasil diubah" << endl;
            break;
        }
    }
    
    if(hitung == 0){
        cout << "|                 TIDAK ADA DATA BARANG                 |" << endl;
    }

    cout << "|_______________________________________________________|" << endl;
    

}

void hapusBarang(string search){
    int hitung = 0;

    for (int i = 0; i < maxrow; i++)
    {
        if(arID[i] == search){
            hitung++;
            arID[i] = "";
            arBarang[i] = "";
            arKuantitas[i] = "";
            arHarga[i] = "";
            cout << "Data berhasil dihapus" << endl;
            break;
        }
    }

    if(hitung == 0){
        cout << "|                 TIDAK ADA DATA BARANG                 |" << endl;
    }

    
    
    
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
            cin.ignore();
            listBarang();
            cout << "=============================================" << endl;
            cout << "|             UPDATE DATA BARANG            |" << endl;
            cout << "=============================================" << endl;
            cout << "Masukkan ID Barang: ";
            getline(cin, id);
            editBarang(id);
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
        
        case 7:
            cin.ignore();
            listBarang();
            cout << "=============================================" << endl;
            cout << "|             HAPUS DATA BARANG             |" << endl;
            cout << "=============================================" << endl;
            cout << "Masukkan ID Barang: ";
            getline(cin, id);
            hapusBarang(id);
            cin.ignore();
            break;
        
        default:
            cout << "Pilihan tidak ada" << endl;
            break;
        }
        } while (pilih != 8);


    
    
}