#include <iostream>
#include <string>
using namespace std;

class Dosen;       // Forward declaration
class Universitas; // Forward declaration

class Mahasiswa
{
private:
    string nama;
    string NIM;
    float nilai;

public:
    Mahasiswa(string n, string id) : nama(n), NIM(id), nilai(0) {}

    void tampilkanInfo()
    {
        cout << "Nama Mahasiswa: " << nama << endl;
        cout << "NIM: " << NIM << endl;
        cout << "Nilai: " << nilai << endl;
    }

    friend class Dosen;
};

class Dosen
{
private:
    string nama;
    string NIDN;
    string pangkat;
    float gaji;

public:
    Dosen(string n, string id, string p, float g) : nama(n), NIDN(id), pangkat(p), gaji(g) {}

    void beriNilai(Mahasiswa *m, float nilaiBaru)
    {
        m->nilai = nilaiBaru;
    }

    void tampilkanInfo()
    {
        cout << "Nama Dosen: " << nama << endl;
        cout << "NIDN: " << NIDN << endl;
        cout << "Pangkat: " << pangkat << endl;
        cout << "(Gaji tidak dapat diakses langsung)" << endl;
    }

    friend class Staff;
    friend float lihatGajiDosen(Dosen *d);
};

class Staff
{
public:
    void ubahPangkat(Dosen *d, string pangkatBaru)
    {
        d->pangkat = pangkatBaru;
    }
};

float lihatGajiDosen(Dosen *d)
{
    return d->gaji;
}

int main()
{
    Mahasiswa m1("Ali", "0147");
    Dosen d1("Dr. Budi", "123456", "Lektor", 8000000);
    Staff s1;

    cout << "=== Sebelum Diberi Nilai ===" << endl;
    m1.tampilkanInfo();

    d1.beriNilai(&m1, 87.5);
    cout << "\n=== Setelah Diberi Nilai Oleh Dosen ===" << endl;
    m1.tampilkanInfo();

    cout << "\n=== Informasi Dosen ===" << endl;
    d1.tampilkanInfo();

    cout << "\n=== Staff Mengubah Pangkat Dosen ===" << endl;
    s1.ubahPangkat(&d1, "Guru Besar");
    d1.tampilkanInfo();

    cout << "\n=== Universitas Melihat Gaji Dosen ===" << endl;
    cout << "Gaji Dosen: Rp. " << lihatGajiDosen(&d1) << endl;

    return 0;
}