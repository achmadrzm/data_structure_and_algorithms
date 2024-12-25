//POINTER
//Mengakses dan Mengubah Isi Suatu Variabel Pointer
#include <iostream>

using namespace std;

int main()
{
	float d = 54.5f, *pd;
	cout << "Isi d mula-mula = " << d << endl;
	pd = &d;
	*pd += 10;
	cout << "Isi d sekarang = " << d << endl;

	cin.get();
	return 0;
}