//  main.cpp
//  CPP
//
//  Created by sgra on 11/09/23.
//

#include <iostream>
#include <vector>
#include <string>

using namespace std;

// Struct untuk Data Mahasiswa
struct Mahasiswa {
    string nama;
    string NRP;
    int umur;
    double IPK;
};

// Display Data
void displayData(const vector<Mahasiswa>& mhs) {
    if (mhs.empty()) {
        cout << "Tidak ada data yang tersimpan.\n";
        return;
    }

    cout << "Data Mahasiswa:\n";
    for (const Mahasiswa& data : mhs) {
        cout << "Nama: " << data.nama << "\n";
        cout << "NRP: " << data.NRP << "\n";
        cout << "Umur: " << data.umur << "\n";
        cout << "IPK: " << data.IPK << "\n\n";
    }
}

// Tambah Data
void addData(vector<Mahasiswa>& mhs) {
    Mahasiswa newData;
    cout << "Masukkan Nama: ";
    cin.ignore();
    getline(cin, newData.nama);
    cout << "Masukkan NRP: ";
    getline(cin, newData.NRP);
    cout << "Masukkan Umur: ";
    cin >> newData.umur;
    cout << "Masukkan IPK: ";
    cin >> newData.IPK;
    mhs.push_back(newData);
    cout << "Data berhasil ditambahkan.\n";
}

// Hapus Data
void deleteData(vector<Mahasiswa>& mhs, const string& NRP) {
    auto it = mhs.begin();
    while (it != mhs.end()) {
        if (it->NRP == NRP) {
            it = mhs.erase(it);
            cout << "Data dengan NRP " << NRP << " berhasil dihapus.\n";
        } else {
            ++it;
        }
    }
}

// Function Edit Data
void editData(vector<Mahasiswa>& mhs, const string& NRP) {
    for (Mahasiswa& data : mhs) {
        if (data.NRP == NRP) {
            cin.ignore();
            cout << "Masukkan Nama yang baru: ";
            getline(cin, data.nama);
            cout << "Masukkan Umur yang baru: ";
            cin >> data.umur;
            cout << "Masukkan IPK yang baru: ";
            cin >> data.IPK;
            cout << "Data berhasil diubah.\n";
            return;
        }
    }
    cout << "Data dengan NRP " << NRP << " tidak ditemukan.\n";
}

int main() {
    vector<Mahasiswa> database;

    while (true) {
        cout << "\nPilih operasi yang ingin Anda lakukan:\n";
        cout << "1. Tampilkan Data Mahasiswa\n";
        cout << "2. Tambah Data Mahasiswa\n";
        cout << "3. Hapus Data Mahasiswa\n";
        cout << "4. Ubah Data Mahasiswa\n";
        cout << "5. Keluar\n";

        int pilihan;
        cin >> pilihan;

        switch (pilihan) {
            case 1:
                displayData(database);
                break;
            case 2:
                addData(database);
                break;
            case 3:
                {
                    string NRP;
                    cout << "Masukkan NRP yang ingin dihapus: ";
                    cin >> NRP;
                    deleteData(database, NRP);
                }
                break;
            case 4:
                {
                    string NRP;
                    cout << "Masukkan NRP yang ingin diubah: ";
                    cin >> NRP;
                    editData(database, NRP);
                }
                break;
            case 5:
                cout << "Program selesai.\n";
                return 0;
            default:
                cout << "Pilihan tidak valid. Silakan coba lagi.\n";
                break;
        }
    }

    return 0;
}
