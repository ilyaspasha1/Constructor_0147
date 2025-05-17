#include <iostream>
#include <string>
using namespace std;

class Dosen; // Forward declaration
class Universitas; // Forward declaration

class Mahasiswa {
private:
    string nama;
    string NIM;
    float nilai;

public:
    Mahasiswa(string n, string id) : nama(n), NIM(id), nilai(0) {}

    void tampilkanInfo() {
        cout << "Nama Mahasiswa: " << nama << endl;
        cout << "NIM: " << NIM << endl;
        cout << "Nilai: " << nilai << endl;
    }

    friend class Dosen;
};

class Dosen {
private:
    string nama;
    string NIDN;
    string pangkat;
    float gaji;

