#include <iostream>
using namespace std;

class mahasiswa{
    public:
        string nama,npm;
};

int main(){

    mahasiswa mhs;

    cin >> mhs.nama >> mhs.npm;
    cout << mhs.nama << " " << mhs.npm;

    return 0;
}
