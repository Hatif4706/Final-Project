#include <iostream> //untuk input dan output
#include <fstream> //untuk file input dan output
#include <sstream> //untuk stringstream (untuk memisahkan data)
#include <iomanip> //untuk format output (untuk memisahkan data)
#include <limits> //untuk limit input (digunakan pada handling error)
using namespace std;

//Maksimal data
const int maxrow = 100;

//Deklarasi array
string arID[maxrow] = {};
string arBarang[maxrow] = {};
string arKuantitas[maxrow] = {};
string arHarga[maxrow] = {};

//Fungsi trim (untuk menghapus spasi di awal dan akhir string, digunakan saat store data ke .txt)
string trim(const string& str) {
    size_t first = str.find_first_not_of(' ');
    size_t last = str.find_last_not_of(' ');
    return (first == string::npos || last == string::npos) ? "" : str.substr(first, (last - first + 1));
}

//Fungsi handling error
void handleNumber(int &number) {
    while (true) {
        cin >> number;

        if (!cin.fail()) {
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); 
            break; 
        }

        cin.clear(); 
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); 


        cout << "Pilihan tidak valid! Silakan Masukkan Pilihan yang Benar: ";
    }
}


// Fungsi untuk mengecek apakah ID sudah ada
bool cekID(const string& searchID) {
    for (int i = 0; i < maxrow; i++) {
        if (arID[i] == searchID) {
            return true; // ID ditemukan, berarti sudah ada
        }
    }
    return false; // ID tidak ditemukan
}



//Fungsi untuk menambah data barang
void tambahBarang() {
    // untuk menampung data
    char id[5];
    char barang[50];
    int kuantitas;
    int harga;

    // meminta input ID dan memeriksa apakah ID sudah ada
    bool idValid = false; // variabel untuk mengecek ID yang valid
    while (!idValid) {
        cout << "Masukkan ID Barang: ";
        cin.getline(id, 5);

        // Cek apakah ID sudah ada menggunakan fungsi isIDExist
        if (cekID(id)) {
            cout << "ID Barang sudah ada! Silakan masukkan ID yang berbeda." << endl;
        } else {
            idValid = true; // Jika ID belum ada, keluar dari perulangan
        }
    }

    cout << "Masukkan Nama Barang: ";
    cin.getline(barang, 50);

    cout << "Masukkan Kuantitas Barang: ";
    handleNumber(kuantitas); 
    cout << "Masukkan Harga Barang: ";
    handleNumber(harga);

    // untuk menyimpan data
    for (int i = 0; i < maxrow; i++) {
        if (arID[i].empty()) { 
            arID[i] = id;
            arBarang[i] = barang;
            arKuantitas[i] = to_string(kuantitas);
            arHarga[i] = to_string(harga);
            cout << "Data berhasil ditambahkan." << endl;
            break;
        }
    }
}



//Fungsi untuk menambah kuantitas barang
void tambahKuantitas(string cari) {
    // untuk menampung data
    int hitung = 0;

    for (int i = 0; i < maxrow; i++) {
        if (arID[i] == cari) {
            hitung++;
            cout << "Masukkan Kuantitas Barang Masuk: ";
            int additionalKuantitas;
            handleNumber(additionalKuantitas); // Use the error-handling function for input

            // Konversi string ke int, lakukan operasi, lalu konversi kembali ke string
            int existingKuantitas = stoi(arKuantitas[i]); 
            int updatedKuantitas = existingKuantitas + additionalKuantitas;

            arKuantitas[i] = to_string(updatedKuantitas); // Simpan hasilnya kembali sebagai string

            cout << "Kuantitas berhasil ditambahkan!" << endl;
            break;
        }
    }

    // untuk tampilan jika data tidak ada
    if (hitung == 0) {
        cout << "|                 TIDAK ADA DATA BARANG                               |" << endl;
    }

    cout << "|_____________________________________________________________________|" << endl;
}


//Fungsi untuk mengurangi kuantitas barang
void kurangKuantitas(string cari) {
    // untuk menampung data
    int hitung = 0;

    for (int i = 0; i < maxrow; i++) {
        if (arID[i] == cari) {
            hitung++;
            cout << "Masukkan Kuantitas Barang Keluar: ";
            int kurangKuantitas;
            handleNumber(kurangKuantitas); // Use the error-handling function for input

            // Konversi string ke int, lakukan operasi, lalu konversi kembali ke string
            int existingKuantitas = stoi(arKuantitas[i]);

            // Handle jika kuantitas yang dikurangi lebih besar dari yang tersedia
            if (kurangKuantitas > existingKuantitas) {
                cout << "Error: Kuantitas keluar melebihi kuantitas tersedia!" << endl;
            } else {
                int updatedKuantitas = existingKuantitas - kurangKuantitas;
                arKuantitas[i] = to_string(updatedKuantitas); // Simpan hasilnya kembali sebagai string
                cout << "Kuantitas berhasil dikurangi." << endl;
            }
            break;
        }
    }

    // untuk tampilan jika data tidak ada
    if (hitung == 0) {
        cout << "|                 TIDAK ADA DATA BARANG                               |" << endl;
    }

    cout << "|_____________________________________________________________________|" << endl;
}


//Fungsi untuk menampilkan data barang
void listBarang(){
    cout << " ______________________________________________________________________" << endl;
    cout << "| NO |                            DATA BARANG                         |" << endl;
    cout << "|    |________________________________________________________________|" << endl;
    cout << "|    |     ID    |   NAMA BARANG   | KUANTITAS |        HARGA         |" << endl;
    cout << "|____|___________|_________________|___________|______________________|" << endl;


    //untuk menampilkan data
    int hitung = 0;
    for (int x = 0; x < maxrow; x++) {
        if (!arID[x].empty()) {  
            hitung++;
            cout << "| " << setw(2) << hitung << " | "
                 << setw(10) << arID[x] << "| "
                 << setw(15) << arBarang[x] << " | "
                 << setw(9) << arKuantitas[x] << " | "
                 << setw(20) << arHarga[x] << " |" << endl;
        }
    }

    //untuk tampilan jika data tidak ada
    if (hitung == 0) {
        cout << "|                 TIDAK ADA DATA BARANG                               |" << endl;
    }

    cout << "|_____________________________________________________________________|" << endl;
}

//Fungsi untuk mencari barang
void cariBarang(string cari){
    //untuk menampung data
    int hitung = 0;

        cout << " ______________________________________________________________________" << endl;
        cout << "| NO |                            DATA BARANG                         |" << endl;
        cout << "|    |________________________________________________________________|" << endl;
        cout << "|    |     ID    |   NAMA BARANG   | KUANTITAS |        HARGA         |" << endl;
        cout << "|____|___________|_________________|___________|______________________|" << endl;

    //untuk mencari data
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

    //untuk tampilan jika data tidak ada
        if (hitung == 0) {
                cout << "|                 TIDAK ADA DATA BARANG                               |" << endl;
        }

    cout << "|_____________________________________________________________________|" << endl;
}

//Fungsi untuk mengedit barang
void editBarang(string search){
    //untuk menampung data
    char id[5];
    char barang[50];
    int kuantitas;
    int harga;

    int pilihUpdate;
    int hitung = 0;

    //untuk mengedit data
    for (int i = 0; i < maxrow; i++)
    {   
        //untuk memilih data apa yang ingin diubah
        if(arID[i] == search){
            hitung++;
            cout << "Apa yang ingin kamu ubah?" << endl;
            cout << "1. Nama Barang" << endl;
            cout << "2. Kuantitas" << endl;
            cout << "3. Harga" << endl;
            cout << "Masukkan Pilihan: ";
            handleNumber(pilihUpdate);
            cin.ignore();

            //untuk mengubah data
            switch (pilihUpdate)
            {
                case 1:
                    cout << "Masukkan Nama Barang Baru: "; 
                    cin.getline(barang, 50);
                    arBarang[i] = barang;
                    break;
            
                case 2:
                    cout << "Masukkan Kuantitas Barang Baru: ";
                    handleNumber(kuantitas);
                    arKuantitas[i] = to_string(kuantitas);
                    break;

                case 3:
                    cout << "Masukkan Harga Barang Baru: ";
                    handleNumber(harga);
                    arHarga[i] = to_string(harga);
                    break;
            
                default:
                    cout << "Pilihan tidak ada" << endl;
                    break;
            }

            cout << "Data berhasil diubah" << endl;
            break;
        }
    }
    
    //untuk tampilan jika data tidak ada
    if (hitung == 0) {
            cout << "|                 TIDAK ADA DATA BARANG                                |" << endl;
        }

        cout << "|______________________________________________________________________|" << endl;
    

}

//Fungsi untuk menghapus barang
void hapusBarang(string search){
    int hitung = 0;

    //untuk menghapus data
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

    //untuk tampilan jika data tidak ada
    if(hitung == 0){
        cout << "|                 TIDAK ADA DATA BARANG                 |" << endl;
    }

}

//Fungsi untuk menyimpan data di file
void SaveData() {
    ofstream myFile("data.txt");


    //format untuk menyimpan data
    myFile << "ID  | NAMA BARANG        | KUANTITAS | HARGA" << endl;
    myFile << "----|--------------------|-----------|--------" << endl;
    for (int x = 0; x < maxrow; x++) {
        if (!arID[x].empty()) {
            myFile << setw(3) << left << arID[x] << " | " 
                   << setw(19) << left << arBarang[x] << "| "  
                   << setw(10) << right << arKuantitas[x] << "| "  
                   << setw(8) << right << arHarga[x] << endl; 
        }
    }

    //untuk menutup file
    myFile.close();
}



//Fungsi untuk memuat data yang ada di file
void loadData() {
    string line;
    ifstream myFile("data.txt");

    //untuk membaca data
    if (myFile.is_open()) {
        int i = 0;

        getline(myFile, line);
        getline(myFile, line);

        //format untuk membaca data
        while (getline(myFile, line)) {
            stringstream ss(line);
            string id, barang, kuantitas, harga;

            //untuk memisahkan data           
            getline(ss, id, '|');
            getline(ss, barang, '|');
            getline(ss, kuantitas, '|');
            getline(ss, harga);

            //untuk memanggil fungsi trim
            arID[i] = trim(id);
            arBarang[i] = trim(barang);
            arKuantitas[i] = trim(kuantitas);
            arHarga[i] = trim(harga);
            
            i++;
        }
        //untuk menutup file
        myFile.close();

    //jika file tidak ditemukan    
    } else {
        cout << "File tidak dapat ditemukan" << endl;
    }
}

//Fungsi untuk membuat struct(kumpulan variable)
struct Variable
{
    bool exitProgram = false;
    string id;
    int pilih;
};

//Fungsi utama
int main(){
    //Deklarasi struct
    Variable v;
    
    //untuk membaca data dari file storage
    loadData();

    //tampilan
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
        
        //untuk memilih menu
        cout << "MASUKKAN PILIHAN ANDA: "; 
        handleNumber(v.pilih); 


        switch (v.pilih)
        {
            //untuk menambah barang
            case 1:
                tambahBarang();
                break;
                
            //untuk menambah kuantitas barang
            case 2:
                listBarang();
                cout << "=============================================" << endl;
                cout << "|             TAMBAH DATA BARANG             |" << endl;
                cout << "=============================================" << endl;
                cout << "Masukkan ID Barang: ";
                getline(cin, v.id);
                tambahKuantitas(v.id);
                break;

            //untuk mengurangi kuantitas barang
            case 3:
                listBarang();
                cout << "=============================================" << endl;
                cout << "|             KURANG DATA BARANG            |" << endl;
                cout << "=============================================" << endl;
                cout << "Masukkan ID Barang: ";
                getline(cin, v.id);
                kurangKuantitas(v.id);
                break;

            //untuk mengedit barang
            case 4:
                listBarang();
                cout << "=============================================" << endl;
                cout << "|             UPDATE DATA BARANG            |" << endl;
                cout << "=============================================" << endl;
                cout << "Masukkan ID Barang: ";
                getline(cin, v.id);
                editBarang(v.id);
                break;

            //untuk menampilkan keseluruhan barang
            case 5:
                listBarang();
                break;

            //untuk mencari barang
            case 6:
                cout << "=============================================" << endl;
                cout << "|             CARI DATA BARANG              |" << endl;
                cout << "=============================================" << endl;
                cout << "Masukkan ID Barang: ";
                getline(cin, v.id);
                cariBarang(v.id);
                break;
            
            //untuk menghapus barang
            case 7:
                listBarang();
                cout << "=============================================" << endl;
                cout << "|             HAPUS DATA BARANG             |" << endl;
                cout << "=============================================" << endl;
                cout << "Masukkan ID Barang: ";
                getline(cin, v.id);
                hapusBarang(v.id);
                break;

            //untuk menyimpan barang dan menyelesaikan program
            case 8:
                SaveData();
                cout << "Data anda telah tersimpan di data kami!" << endl;
                v.exitProgram = true; 
                break;

            //untuk pilihan yang salah
            default:
                cout << "Pilihan tidak valid! Silakan masukkan pilihan yang benar." << endl;
                cout << "MASUKKAN PILIHAN ANDA: ";
                handleNumber(v.pilih);  
                break;

        }
        } while (!v.exitProgram);

        return 0;

}