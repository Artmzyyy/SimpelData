#include <iostream>
#include <fstream>
using namespace std;

struct Siswa {
    string nama;
    int nilai;
    char kelas;
};

int main() {
    int pilihan;
    string namaFile = "data.txt";
	
    do {
    	
        cout << "\n=== MENU ===\n";
        cout << "1. Tambah Data\n";
        cout << "2. Tampilkan Data\n";
        cout << "3. Cari Data\n";
        cout << "4. Keluar\n";
        cout << "Pilih menu (1-4): ";
        cin >> pilihan;

        if (pilihan == 1) {
            int jumlah;
            cout << "Masukkan jumlah data yang ingin ditambahkan: ";
            cin >> jumlah;
            Siswa data[jumlah];

            for (int i = 0; i < jumlah; i++) {
                cout << "Nama siswa ke-" << i + 1 << ": ";
                cin >> data[i].nama;
                cout << "Nilai siswa ke-" << i + 1 << ": ";
                cin >> data[i].nilai;
                cout << "Kelas siswa ke-" << i + 1 << ": ";
                cin >> data[i].kelas;
             }
		    for (int i = 0; i < jumlah - 1; i++) {
		        for (int j = 0; j < jumlah - i - 1; j++) {
		            if (data[j].nilai < data[j + 1].nilai) {
		                Siswa temp = data[j];
		                data[j] = data[j + 1];
		                data[j + 1] = temp;
		            }
		        }
		    }
		    
			cout << "\nData setelah diurutkan:\n";
			    for (int i = 0; i < jumlah; i++) {
			        cout << data[i].nama << " - " << data[i].nilai << " - " << data[i].kelas << endl;
			    }

            ofstream fileOut("data.txt", ios::app);
            for (int i = 0; i < jumlah; i++) {
                fileOut << data[i].nama << " " << data[i].nilai << " " << data[i].kelas << endl;
            }
            fileOut.close();
            cout << "Data berhasil ditambahkan.\n";

        } else if (pilihan == 2) {
            ifstream fileIn("data.txt");
            string nama;
            int nilai;
            char kelas;
            cout << "\n=== Data dari file ===\n";
            while (fileIn >> nama >> nilai >> kelas) {
                cout << "Nama: " << nama << " - Nilai: " << nilai << " - Kelas: " << kelas << endl;
            }
            fileIn.close();

        } else if (pilihan == 3) {
            string cariNama;
            bool ketemu = false;
            cout << "Masukkan nama siswa yang ingin dicari: ";
            cin >> cariNama;

            ifstream fileIn("data.txt");
            string nama;
            int nilai;
            char kelas;
            while (fileIn >> nama >> nilai) {
                if (nama == cariNama) {
                    cout << "Data ditemukan: " << nama << " - Nilai: " << nilai << " - Kelas: " << kelas << endl;
                    ketemu = true;
                    break;
                }
            }
            fileIn.close();

            if (!ketemu) {
                cout << "Data tidak ditemukan.\n";
            }
        }
    } while (pilihan != 4);

    cout << "Terima kasih telah menggunakan program.\n";
    return 0;
}
