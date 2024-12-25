//POINTER
//Mengubah Isi Variabel Melalui Pointer
#include <iostream>

using namespace std;

int main()
{
	int y, x = 87; 	// x & y bertipe int 
	int *px;	// var pointer yang menunjuk ke data yang bertipe int
	px = &x;	// px diisi dengan alamat dari variabel x
	y = *px; 	// y diisi dengan nilai yg ditunjuk oleh px
	cout << "Alamat x = " << &x << endl;
	cout << "Isi px = " << px << endl;
	cout << "Isi x = " << x << endl;
	cout << "Nilai yang ditunjuk oleh px = " << *px << endl;
	cout << "Nilai y = " << y << endl;

	cin.get();
	return 0;
}