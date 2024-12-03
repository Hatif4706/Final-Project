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

void tambahKuantitas(string cari) {
    int hitung = 0;

    for (int i = 0; i < maxrow; i++) {
        if (arID[i] == cari) {
            hitung++;
            cout << "Masukkan Kuantitas Barang Masuk: ";
            string inputKuantitas;
            getline(cin, inputKuantitas);

           
            int existingKuantitas = stoi(arKuantitas[i]); 
            int additionalKuantitas = stoi(inputKuantitas); 


            int updatedKuantitas = existingKuantitas + additionalKuantitas;


            arKuantitas[i] = to_string(updatedKuantitas);

            cout << "Kuantitas berhasil ditambahkan!" << endl;
            break;
        }
    }

    if (hitung == 0) {
        cout << "|                 TIDAK ADA DATA BARANG                               |" << endl;
    }

    cout << "|_____________________________________________________________________|" << endl;
}

void kurangKuantitas(string cari){
    int hitung = 0;
    int kurangKuantitas = 0;

    for (int i = 0; i < maxrow; i++) {
        if (arID[i] == cari) {
            hitung++;
            cout << "Masukkan Kuantitas Barang Keluar: ";
            cin >> kurangKuantitas;

            int kuantitasBarang = stoi(arKuantitas[i]);
            if (kurangKuantitas > kuantitasBarang) {
                cout << "Error: Kuantitas keluar melebihi kuantitas tersedia!" << endl;
            } else {
                kuantitasBarang -= kurangKuantitas;
                arKuantitas[i] = to_string(kuantitasBarang); 
                cout << "Kuantitas berhasil dikurangi." << endl;
            }
            break;
        }
    }

    if (hitung == 0) {
        cout << "|                 TIDAK ADA DATA BARANG                               |" << endl;
    }

    cout << "|_____________________________________________________________________|" << endl;
}

void listBarang(){
    int hitung = 0;

        cout << " ______________________________________________________________________" << endl;
        cout << "| NO |                            DATA BARANG                         |" << endl;
        cout << "|    |________________________________________________________________|" << endl;
        cout << "|    |     ID    |   NAMA BARANG   | KUANTITAS |        HARGA         |" << endl;
        cout << "|____|___________|_________________|___________|______________________|" << endl;

         for (int i = 0; i < maxrow; i++) {
            if (arID[i] != "\0") {
                hitung++;
                cout << "| " << setw(2) << hitung << " | "   
                    << setw(9) << arID[i] << " | "    
                    << setw(15) << arBarang[i] << " | "  
                    << setw(9) << arKuantitas[i] << " | "  
                    << setw(20) << arHarga[i] << " |" << endl; 
        }
    }

    if (hitung == 0) {
        cout << "|                 TIDAK ADA DATA BARANG                               |" << endl;
    }

    cout << "|_____________________________________________________________________|" << endl;
        
}

void cariBarang(string cari){
    int hitung = 0;

        cout << " ______________________________________________________________________" << endl;
        cout << "| NO |                            DATA BARANG                         |" << endl;
        cout << "|    |________________________________________________________________|" << endl;
        cout << "|    |     ID    |   NAMA BARANG   | KUANTITAS |        HARGA         |" << endl;
        cout << "|____|___________|_________________|___________|______________________|" << endl;

    for(int i = 0; i < maxrow; i++){
        if (arID[i] == cari){
            hitung++;
            cout << "| " << setw(2) << hitung << " | "   
                    << setw(9) << arID[i] << " | "    
                    << setw(15) << arBarang[i] << " | "  
                    << setw(9) << arKuantitas[i] << " | "  
                    << setw(20) << arHarga[i] << " |" << endl; 
            break;
        }
    }

        if (hitung == 0) {
                cout << "|                 TIDAK ADA DATA BARANG                               |" << endl;
        }

    cout << "|_____________________________________________________________________|" << endl;
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
    
if (hitung == 0) {
        cout << "|                 TIDAK ADA DATA BARANG                                |" << endl;
    }

    cout << "|______________________________________________________________________|" << endl;
    

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

void saveData() {
    ofstream outFile("dataBarang.txt");

    if (!outFile) {
        cout << "Error: Tidak bisa membuka file untuk menyimpan data karena data kosong!" << endl;
        return;
    }


    outFile << " _____________________________________________________________________" << endl;
    outFile << "| NO |                            DATA BARANG                         |" << endl;
    outFile << "|    |________________________________________________________________|" << endl;
    outFile << "|    |     ID    |   NAMA BARANG   | KUANTITAS |        HARGA         |" << endl;
    outFile << "|____|___________|_________________|___________|______________________|" << endl;

    int hitung = 0;

    for (int i = 0; i < maxrow; i++) {
        if (arID[i] != "\0" && arID[i] != "") {
            hitung++;
            outFile << "| " << setw(2) << hitung << " | "   
                    << setw(9) << arID[i] << " | "    
                    << setw(15) << arBarang[i] << " | "  
                    << setw(9) << arKuantitas[i] << " | "  
                    << setw(20) << arHarga[i] << " |" << endl; 
        }
    }


    if (hitung == 0) {
        outFile << "|                 TIDAK ADA DATA BARANG                               |" << endl;
    }

    outFile << "|_____________________________________________________________________|" << endl;

    outFile.close();
    cout << "Data berhasil disimpan ke file data_barang.txt!" << endl;
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
                cin.ignore();
                listBarang();
                cout << "=============================================" << endl;
                cout << "|             TAMBAH DATA BARANG            |" << endl;
                cout << "=============================================" << endl;
                cout << "Masukkan ID Barang: ";
                getline(cin, id);
                tambahKuantitas(id);
                break;

            case 3:
                cin.ignore();
                listBarang();
                cout << "=============================================" << endl;
                cout << "|             KURANG DATA BARANG            |" << endl;
                cout << "=============================================" << endl;
                cout << "Masukkan ID Barang: ";
                getline(cin, id);
                kurangKuantitas(id);
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

        }
        } while (pilih != 8);

        saveData();
        cout << "Terimakasih telah menggunakan program ini!" << endl;
        return 0;

}