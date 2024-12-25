//ARRAY & STRUCT
//Struct of Array
#include <iostream>

using namespace std;

struct Mahasiswa{
	char nama[30];
	char nim[15]; 
	float nilai[3];
};

int main()
{
	Mahasiswa mhs;
	int sum=0, jmlNilai=sizeof(mhs.nilai)/sizeof(*mhs.nilai);
	
	mhs.nilai[0] = 95;
	mhs.nilai[1] = 90;
	mhs.nilai[2] = 85;
	
	for (int i = 0; i < jmlNilai ; i++)
		sum += mhs.nilai[i];
	
	cout << "Rata-rata yang diperoleh adalah : ";
	cout << sum/jmlNilai;
		
	cin.get();
	return 0;
}