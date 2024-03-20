#include <iostream> 
using namespace std;

struct Mahasiswa{
	public:
		string:
			string nama;
			
		public: 
		      void setNama(string nama){
		      	      this->nama = nama;
			  }
			  string getNama() {
			  	return nama;
			  }
		
	
		}


int main(){
	Mahasiswa Mhs;
	
	mhs.setName("anta");
	
	cout << "Nama: " << Mhs.getNama() << endl;
}
