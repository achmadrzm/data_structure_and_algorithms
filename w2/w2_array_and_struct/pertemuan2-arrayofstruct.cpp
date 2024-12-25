//ARRAY & STRUCT
//Array of Struct
#include <iostream>
#include <cstring>

using namespace std;

struct Mahasiswa{
	char nama[30];
	char nim[15]; 
	float nilai[3];
};

int main()
{
	Mahasiswa mhs[3];
	int jmlMhs = sizeof(mhs)/sizeof(*mhs);
	
	strcpy(mhs[0].nama, "Sulistyo");
	strcpy(mhs[0].nim, "123456789054321");
		
	strcpy(mhs[1].nama, "Kornelia");
	strcpy(mhs[1].nim, "987654321012345");
		
	strcpy(mhs[2].nama, "Firmansyah");
	strcpy(mhs[2].nim, "543210123456789");
	
	cout << "Data mahasiswa : " << endl;
	for (int i = 0; i < jmlMhs ; i++) {
		cout << "Mahasiswa ke-" << i+1 << ":" << endl;
		cout << "\tNama : " << mhs[i].nama << endl;
		cout << "\tNIM : " << mhs[i].nim << endl << endl;
	}
		
	cin.get();
	return 0;
}