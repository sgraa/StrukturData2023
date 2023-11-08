#include <iostream>
#include <list>
#include <string>

using namespace std;

class Album {
public:
    string title;
    string artist;
    int year;

    Album(const string& t, const string& a, int y) : title(t), artist(a), year(y) {}
};

void displayMusicLibrary(const list<Album>& musicLibrary) {
    cout << "Daftar Album Musik:" << endl;
    for (const Album& album : musicLibrary) {
        cout << "Judul: " << album.title << ", Artis: " << album.artist << ", Tahun: " << album.year << endl;
    }
}

void addAlbum(list<Album>& musicLibrary, const Album& album) {
    musicLibrary.push_back(album);
    cout << "Album berhasil ditambahkan ke dalam daftar." << endl;
}

void searchAlbum(const list<Album>& musicLibrary, const string& title) {
    for (const Album& album : musicLibrary) {
        if (album.title == title) {
            cout << "Album ditemukan:" << endl;
            cout << "Judul: " << album.title << ", Artis: " << album.artist << ", Tahun: " << album.year << endl;
            return;
        }
    }
    cout << "Album dengan judul '" << title << "' tidak ditemukan dalam daftar." << endl;
}

void removeAlbum(list<Album>& musicLibrary, const string& title) {
    for (auto it = musicLibrary.begin(); it != musicLibrary.end(); ++it) {
        if (it->title == title) {
            musicLibrary.erase(it);
            cout << "Album dengan judul '" << title << "' berhasil dihapus dari daftar." << endl;
            return;
        }
    }
    cout << "Album dengan judul '" << title << "' tidak ditemukan dalam daftar." << endl;
}

void editAlbum(list<Album>& musicLibrary, const string& title, const Album& newAlbum) {
    for (auto& album : musicLibrary) {
        if (album.title == title) {
            album = newAlbum;
            cout << "Album dengan judul '" << title << "' berhasil disunting." << endl;
            return;
        }
    }
    cout << "Album dengan judul '" << title << "' tidak ditemukan dalam daftar." << endl;
}

int main() {
    list<Album> musicLibrary;
    const string separator = "==============================";

    while (true) {
        cout << "Pilih tindakan\n 1: Tambah\n 2: Cari\n 3: Hapus\n 4: Sunting\n 5: Tampilkan\n 6: Keluar\n ";
        int choice;
        cin >> choice;

        if (choice == 6) {
            break; // Keluar dari loop jika pengguna memilih opsi 6
        }

        cin.ignore(); // Menghapus karakter newline dari buffer

        switch (choice) {
            case 1: {
                string title, artist;
                int year;
                cout << "Judul album: ";
                getline(cin, title);
                cout << "Artis album: ";
                getline(cin, artist);
                cout << "Tahun rilis: ";
                cin >> year;
                addAlbum(musicLibrary, Album(title, artist, year));
                break;
            }

            case 2: {
                string title;
                cout << "Masukkan judul album yang ingin Anda cari: ";
                cin.ignore();
                getline(cin, title);
                searchAlbum(musicLibrary, title);
                break;
            }

            case 3: {
                string title;
                cout << "Masukkan judul album yang ingin Anda hapus: ";
                cin.ignore();
                getline(cin, title);
                removeAlbum(musicLibrary, title);
                break;
            }

            case 4: {
                string title, newTitle, newArtist;
                int newYear;
                cout << "Masukkan judul album yang ingin Anda sunting: ";
                cin.ignore();
                getline(cin, title);
                cout << "Judul album baru: ";
                getline(cin, newTitle);
                cout << "Artis album baru: ";
                getline(cin, newArtist);
                cout << "Tahun rilis baru: ";
                cin >> newYear;
                Album newAlbum(newTitle, newArtist, newYear);
                editAlbum(musicLibrary, title, newAlbum);
                break;
            }

            case 5: {
                displayMusicLibrary(musicLibrary); 
                break;
            }

            default:
                cout << "Pilihan tidak valid. Silakan pilih kembali." << endl;
        }
    }

    displayMusicLibrary(musicLibrary);

    return 0;
}
