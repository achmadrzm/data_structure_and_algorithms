//ALOKASI MEMORI
//Malloc
#include <iostream>

using namespace std;

int main()
{
	int num, i, *ptr, sum = 0;
	cout << "Enter number of elements: ";
	cin >> num;
	ptr = (int*) malloc(num * sizeof(int)); 
	if(ptr == NULL)                     
	{
		cout << "Error! memory not allocated.";
		exit(0);
	}

	cout << "Enter elements of array: ";    
	for(i = 0; i < num; ++i)
	{
		cin >> *(ptr + i);
		sum += *(ptr + i);
	}
	cout << "Sum = " << sum << "\n";
	free(ptr);
		
	cin.get();
	return 0;
}