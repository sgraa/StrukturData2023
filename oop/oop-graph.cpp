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

    Titik() : id(0), x(0), y(0) {} 

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

    void tampilkanAdjacencyMatrix() {
        int n = titikList.size();
        std::vector<std::vector<int>> adjacencyMatrix(n, std::vector<int>(n, 0));

        for (const auto& pair : adjacencyList) {
            int from = pair.first;
            for (int to : pair.second) {
                adjacencyMatrix[from - 1][to - 1] = 1;
            }
        }

        std::cout << "Adjacency Matrix:\n";
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                std::cout << adjacencyMatrix[i][j] << " ";
            }
            std::cout << std::endl;
        }
    }

    void tampilkanGraf() {
        initwindow(1500, 1500); 

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

            
            char* nama = const_cast<char*>(pair.second.nama.c_str());

            outtextxy(x, y, nama);
        }

        getch(); 
        closegraph(); 
    }
};

int main() {
    Peta petaSighra;

    //titik peta
    petaSighra.tambahTitik(1, "Apartemen", 800, 400);
    petaSighra.tambahTitik(2, "Hypermart", 740, 240);
    petaSighra.tambahTitik(3, "Superindo", 600, 240);
    petaSighra.tambahTitik(4, "Gerbang Keputih", 400,240);
    petaSighra.tambahTitik(5, "Asrama ITS", 450, 350);
    petaSighra.tambahTitik(6, "Kmart ITS", 410, 450);
    petaSighra.tambahTitik(7, "Tower 1 ITS", 460, 670);
    petaSighra.tambahTitik(8, "Departemen Biologi", 460, 630);
    petaSighra.tambahTitik(9, "Tower 2 ITS", 370, 570);
    petaSighra.tambahTitik(10, "Perumdos", 100, 550);
    petaSighra.tambahTitik(11, "Warteg Gebang", 800, 900);
    petaSighra.tambahTitik(12, "Telkomsel", 1300, 570);
    petaSighra.tambahTitik(13, "Polsek", 1280, 500);
   
  
    //edge kayak microsofdt edge
    petaSighra.tambahEdge(1, 2);
    petaSighra.tambahEdge(2, 3);
    petaSighra.tambahEdge(3, 4);
    petaSighra.tambahEdge(4, 5);
    petaSighra.tambahEdge(5, 6);
    petaSighra.tambahEdge(6, 9);
    petaSighra.tambahEdge(9, 10);
    petaSighra.tambahEdge(10, 8);
    petaSighra.tambahEdge(8, 7);
    petaSighra.tambahEdge(7, 11);
    petaSighra.tambahEdge(11, 1);
    petaSighra.tambahEdge(1, 3);
    petaSighra.tambahEdge(2, 3);
    petaSighra.tambahEdge(6, 10);
    petaSighra.tambahEdge(9, 8);
    petaSighra.tambahEdge(2, 13);
    petaSighra.tambahEdge(11, 12);
    petaSighra.tambahEdge(12,13);
    petaSighra.tambahEdge(12, 2);
    petaSighra.tambahEdge(13,11);



    std::cout << "Adjacency List:\n";
    petaSighra.tampilkanAdjacencyList();

    petaSighra.tampilkanAdjacencyMatrix();

    std::cout << "\nNama Tempat:\n";
    petaSighra.tampilkanNamaTempat();

    petaSighra.tampilkanGraf();

    return 0;
}
