#include <iostream> 
using namespace std;

struct Mahasiswa{
	public:
		string nama, npm;
		
		Mahasiswa(string nama, string x) {
			this->nama = nama;
			this->npm = x;
		}
};

int main(){
	Mahasiswa Mhs("Reza","2117");
	
	cout << "Nama: " << Mhs.nama << endl;
	cout << "Npm: " << Mhs.npm << endl;
}
