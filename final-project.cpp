#include <iostream>
#include <fstream>
#include <sstream>
#include <limits>
#include <iomanip>
using namespace std;

const int maxrow = 100;

string arID[maxrow] = {};
string arBarang[maxrow] = {};
string arKuantitas[maxrow] = {};
string arHarga[maxrow] = {};


string trim(const string& str) {
    size_t first = str.find_first_not_of(' ');
    size_t last = str.find_last_not_of(' ');
    return (first == string::npos || last == string::npos) ? "" : str.substr(first, (last - first + 1));
}

void tambahBarang() {
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

    for (int i = 0; i < maxrow; i++) {
        if (arID[i].empty()) { // Use .empty() to check for an empty slot
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
    cout << " ______________________________________________________________________" << endl;
    cout << "| NO |                            DATA BARANG                         |" << endl;
    cout << "|    |________________________________________________________________|" << endl;
    cout << "|    |     ID    |   NAMA BARANG   | KUANTITAS |        HARGA         |" << endl;
    cout << "|____|___________|_________________|___________|______________________|" << endl;

    int hitung = 0;

    for (int x = 0; x < maxrow; x++) {
        if (!arID[x].empty()) {  // Check if ID is not empty
            hitung++;
            // Format and print the data in the specified format
            cout << "| " << setw(3) << hitung << " | "
                 << setw(10) << arID[x] << " | "
                 << setw(15) << arBarang[x] << " | "
                 << setw(9) << arKuantitas[x] << " | "
                 << setw(20) << arHarga[x] << " |" << endl;
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

void SaveData() {
    ofstream myFile;
    myFile.open("data.txt");

    // Loop through each item and save its data in the correct format
    for (int x = 0; x < maxrow; x++) {
        if (!arID[x].empty()) {
            // Save the ID, Barang, Kuantitas, and Harga, separated by "|"
            myFile << arID[x] << " | "
                   << arBarang[x] << " | "
                   << arKuantitas[x] << " | "
                   << arHarga[x] << endl;
        }
    }

    myFile.close();
}

void loadData() {
    string line;
    ifstream myFile("data.txt");
    if (myFile.is_open()) {
        int x = 0;
        while (getline(myFile, line)) {
            // Find the position of each delimiter ("|")
            stringstream ss(line);
            string id, barang, kuantitas, harga;

            // Parse the line by extracting each field separated by " | "
            getline(ss, id, '|');
            getline(ss, barang, '|');
            getline(ss, kuantitas, '|');
            getline(ss, harga);

            // Remove any leading/trailing whitespace
            id = trim(id);
            barang = trim(barang);
            kuantitas = trim(kuantitas);
            harga = trim(harga);

            // Store the parsed data into the arrays
            arID[x] = id;
            arBarang[x] = barang;
            arKuantitas[x] = kuantitas;
            arHarga[x] = harga;
            
            x++;
        }
        myFile.close();
    } else {
        cout << "Unable to open file" << endl;
    }
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

    loadData();

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

        SaveData();
        cout << "Terimakasih telah menggunakan program ini!" << endl;
        return 0;

}