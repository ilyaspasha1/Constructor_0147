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