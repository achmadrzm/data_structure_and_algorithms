#include <iostream>
#define MAX 5

using namespace std;

int queue[MAX];
int count = 0;

void enqueue(int i)
{
    if (count < MAX)
    {
        queue[count] = i;
        count++;
    }
    else
    {
        cout << "Queue Full!" << endl;
    }
}

void dequeue()
{
    if (count > 0)
    {
        int p = queue[0];
        for (int i = 0; i < count - 1; i++)
        {
            queue[i] = queue[i + 1];
        }
        count--;
        cout << "Poll: " << p << endl;
    }
}

void print()
{
    if (count == 0)
    {
        cout << "Kosong" << endl;
        return;
    }

    for (int i = 0; i < count; i++)
    {
        cout << queue[i] << " ";
    }

    cout << endl;
}

int main()
{
    enqueue(2);
    enqueue(3);
    enqueue(4);
    enqueue(5);
    enqueue(6);
    enqueue(7);
    enqueue(8);
    enqueue(9);
    enqueue(10);
    enqueue(11);
    print();
    dequeue();
    print();
    enqueue(100);
    print();
    dequeue();
    print();
}