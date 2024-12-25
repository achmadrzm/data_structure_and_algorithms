//ARRAY & STRUCT
//Array
#include <cstdlib>
#include <iostream>

#define MAX 20

using namespace std;

int fibo[MAX];

int main()
{
	int i;
	fibo[1] = 1;
	fibo[2] = 1;
	for (i=3;i<=MAX;i++)
		fibo[i]=fibo[i-2]+fibo[i-1];

	cout<<MAX<<" Bilangan Fibonaci Pertama adalah : "<<endl;

	for (i=1;i<MAX;i++)
		cout<<fibo[i]<<endl;

	cin.get();
	return 0;
}