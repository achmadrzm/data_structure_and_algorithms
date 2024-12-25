//ARRAY & STRUCT
//Penggunaan Struktur pada Konversi Koordinat Polar ke Koordinat Cartesian
#include <cstdlib>
#include <iostream>
#include <cmath>

using namespace std;

struct polar {
	double r;
	double alpha;
};

struct kartesian {
	double x;
	double y;
};

int main()
{
	struct polar p1;
	struct kartesian k1;
	
	cout << "Masukkan nilai r untuk koordinat polar : ";
	cin >> p1.r;
	
	cout << "Masukkan nilai alpha untuk koordinat polar : ";
	cin >> p1.alpha;

	k1.x = p1.r * cos(p1.alpha);
	k1.y = p1.r * sin(p1.alpha);

	cout << "Nilai koordinat kartesian untuk koordinat polar r = " << p1.r << " alpha = " << p1.alpha << " adalah:" << 			endl;
	cout << "x = " << k1.x << " y = " << k1.y << endl;

	cin.get();
	return 0;
}