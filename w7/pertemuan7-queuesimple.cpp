#include <iostream>
using namespace std;

struct node
{
    int data;
    string nama;
    node *next = NULL;
};
struct queue
{
    node *head = NULL;

    bool empty()
    {
        return head == NULL;
    }

    void enqueue(string data)
    {
        node *newNode = new node;
        newNode->nama = data;

        if (empty())
        {
            newNode->next = head;
            head = newNode;
        }
        else
        {
            node *t = head;
            while (t->next != NULL)
            {
                t = t->next;
            }
            newNode->next = t->next;
            t->next = newNode;
        }
    }

    int dequeue()
    {
        if (!empty())
        {
            node *t = head;
            head = head->next;
            int temp = t->data;
            delete t;
            return temp;
        }
    }

    void print()
    {
        if (!empty())
        {
            node *t = head;
            cout << "list nama dalam antrian : " << endl;
            do
            {
                cout << t->nama <<endl;
                t = t->next;
            } while (t != NULL);
            cout << endl;
        }else {
            cout << "QUEUE KOSONG!!!" << endl;
        }
    }
};

int main()
{
    queue q1;
    q1.print();
    q1.enqueue("Udin");
    q1.print();
}

