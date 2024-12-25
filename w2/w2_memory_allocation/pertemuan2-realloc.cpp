//ALOKASI MEMORI
//Realloc
#include <iostream>

using namespace std;

int main()
{
	int *ptr, i , n1, n2;
	cout << "Enter size of array: ";
	cin >> n1;

	ptr = (int*) malloc(n1 * sizeof(int));

	cout << "Address of previously allocated memory: " << endl;
	for(i = 0; i < n1; ++i)
		cout << (ptr + i) << endl;

	cout << "Enter new size of array: ";
	cin >> n2;
	realloc((int*) ptr, n2);
	for(i = 0; i < n2; ++i)
		cout << (ptr + i) << endl;
		
	cin.get();
	return 0;
}