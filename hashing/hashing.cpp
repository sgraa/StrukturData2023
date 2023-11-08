#include <iostream>
#include <string>
using namespace std;

const int SIZE_ARR = 26;

struct HashTable
{
    string username, password;
} dataAkun[SIZE_ARR];

int hashFunction(string username)
{
    int hash = 0;
    int prime = 31; // Bilangan prima yang digunakan untuk menghindari kolisi

    for (int i = 0; i < username.length(); i++)
    {
        hash = (hash * prime + username[i]) % SIZE_ARR;
    }

    return hash;
}

void printAll()
{
    for (int i = 0; i < SIZE_ARR; i++)
    {
        cout << i << " [ " << dataAkun[i].username << " - " << dataAkun[i].password << " ]" << endl;
    }
}

void menu()
{
    while (true)
    {
        int input_user;

        cout << endl;
        cout << "MENU" << endl;
        cout << "1. Register" << endl;
        cout << "2. Login" << endl;
        cout << "3. Exit" << endl
             << endl;

        cout << "Pilih: ";
        cin >> input_user;
        cout << endl;

        if (input_user == 1)
        {
            string username, password;

            cout << "Masukkan Username: ";
            cin >> username;
            cout << "Masukkan Password: ";
            cin >> password;

            int index = hashFunction(username);

            if (dataAkun[index].username.empty() && dataAkun[index].password.empty())
            {
                dataAkun[index].username = username;
                dataAkun[index].password = password;
                cout << "Registrasi berhasil!" << endl;
            }
            else
            {
                cout << "Akun sudah ada!" << endl;
            }
        }
        else if (input_user == 2)
        {
            string username, password;

            cout << "Masukkan Username: ";
            cin >> username;
            cout << "Masukkan Password: ";
            cin >> password;

            int index = hashFunction(username);

            if (dataAkun[index].username == username && dataAkun[index].password == password)
            {
                cout << "Login berhasil!" << endl;
            }
            else
            {
                cout << "Login gagal. Periksa username dan password Anda." << endl;
            }
        }
        else if (input_user == 3)
        {
            printAll();
            break;
        }
        else
        {
            cout << "Invalid!" << endl;
        }
    }
}

int main()
{
    menu();
    return 0;
}
