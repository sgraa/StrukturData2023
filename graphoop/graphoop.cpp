#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <conio.h>
#include <graphics.h>

class Titik {
public:
    int id;
    std::string nama;
    int x;
    int y;

    Titik() : id(0), x(0), y(0) {} // Konstruktor default

    Titik(int _id, const std::string& _nama, int _x, int _y) : id(_id), nama(_nama), x(_x), y(_y) {}
};

class Peta {
public:
    std::map<int, Titik> titikList;
    std::map<int, std::vector<int>> adjacencyList;

    void tambahTitik(int id, const std::string& nama, int x, int y) {
        Titik titik(id, nama, x, y);
        titikList[id] = titik;
    }

    void tambahEdge(int from, int to) {
        adjacencyList[from].push_back(to);
    }

    void tampilkanAdjacencyList() {
        for (const auto& pair : adjacencyList) {
            std::cout << "Titik " << titikList[pair.first].nama << " terhubung ke: ";
            for (int neighbor : pair.second) {
                std::cout << titikList[neighbor].nama << " ";
            }
            std::cout << std::endl;
        }
    }

    void tampilkanNamaTempat() {
        for (const auto& pair : titikList) {
            std::cout << "Titik " << pair.first << ": " << pair.second.nama << std::endl;
        }
    }

    void tampilkanGraf() {
        initwindow(800, 600); // Inisialisasi window grafis

        for (const auto& pair : adjacencyList) {
            int x1 = titikList[pair.first].x;
            int y1 = titikList[pair.first].y;

            for (int neighbor : pair.second) {
                int x2 = titikList[neighbor].x;
                int y2 = titikList[neighbor].y;

                line(x1, y1, x2, y2);
            }
        }

        for (const auto& pair : titikList) {
            int x = pair.second.x;
            int y = pair.second.y;

            // Konversi string ke char* sebelum menggunakannya dalam outtextxy
            char* nama = const_cast<char*>(pair.second.nama.c_str());

            outtextxy(x, y, nama);
        }

        getch(); // Tunggu input dari pengguna sebelum menutup window
        closegraph(); // Tutup window grafis
    }
};

int main() {
    Peta petaSurabaya;

    // Menambahkan titik ke dalam peta
    petaSurabaya.tambahTitik(1, "Rumah", 100, 100);
    petaSurabaya.tambahTitik(2, "Minimarket", 200, 200);
    petaSurabaya.tambahTitik(3, "Apotek", 300, 300);
    petaSurabaya.tambahTitik(4, "Kantor", 400, 400);

    // Menambahkan edge antar titik
    petaSurabaya.tambahEdge(1, 2);
    petaSurabaya.tambahEdge(2, 3);
    petaSurabaya.tambahEdge(3, 4);
    petaSurabaya.tambahEdge(4, 1);

    // Menampilkan adjacency list
    std::cout << "Adjacency List:\n";
    petaSurabaya.tampilkanAdjacencyList();

    // Menampilkan nama tempat
    std::cout << "\nNama Tempat:\n";
    petaSurabaya.tampilkanNamaTempat();

    // Menampilkan graf menggunakan library graphics.h
    petaSurabaya.tampilkanGraf();

    return 0;
}
