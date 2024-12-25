//POINTER
//Penggunaan Pointer untuk Bilangan Fibonaci
#include <cstdlib>
#include <iostream>

#define MAX 20

using namespace std;

int *fibo;
int main()
{
	int i;
	fibo = (int*) malloc(MAX * sizeof(int));
	*(fibo + 1) = 1;
	*(fibo + 2) = 1;
	
	for (i=3;i<=MAX;i++)
		*(fibo + i) = (*(fibo + i - 2) + *(fibo + i - 1));
	cout<<MAX<<" Bilangan Fibonaci Pertama adalah : "<<endl;
	
	for (i=1;i<MAX;i++)
		cout << *(fibo+i) << endl;
		
	cin.get();
	return 0;
}