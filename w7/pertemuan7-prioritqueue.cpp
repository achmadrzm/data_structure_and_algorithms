#include <iostream>
using namespace std;
int count = 0;

struct node
{
    string nama;
    int umur;
    int prio;
    node *next;
};

node *head = NULL, *tail = NULL;

void enqueue(string nama, int umur, int prio = 0)
{
    count++;
    node *newnode = new node;
    newnode->nama = nama;
    newnode->umur = umur;
    newnode->prio = prio;
    
    if (head == NULL || prio > head->prio)
    {
        newnode->next = head;
        head = newnode;
    }
    else 
    {
        node *temp = head;
        while (temp->next != NULL && temp->next->prio >= prio )
        {
            temp = temp->next;
        }
        newnode->next = temp->next;
        temp->next = newnode;
    }
    
}

void dequeue()
{
    node *t = head;
    head = head->next;
    delete t;
    count--;
}

void print()
{
    node *temp = head;
    cout << "Nama \t|\t" << "umur \t|\t" << "prioritas \n";
    cout << "=========================================" << endl;
    while (temp != NULL)
    {
        cout << temp->nama << "\t|\t" << temp->umur << "\t|\t" << temp->prio;
        cout << endl;
        cout << "=========================================" << endl;
        temp = temp->next;
    }
    cout <<endl;

    cout << "count = " << count;
    cout <<endl;

    
}

int main()
{
    // for (int i = 1; i < 10; i++)
    // {
    //     enqueue("udin",100, i);
    // }
    enqueue("danish",12,1);
    enqueue("udin",9);
    print();
    enqueue("yuda",30,100);
    print();
}