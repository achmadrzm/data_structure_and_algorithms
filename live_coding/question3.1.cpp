#include <iostream>
#include <sstream>

using namespace std;

struct node
{
    string nama;
    int persentase;
    node *next;
    node *previous;
};

node *head, *tail;
int nodeSize = 0;

node *createNode(string nama, int persentase)
{
    node *newNode = new node;
    newNode->nama = nama;
    newNode->persentase = persentase;
    newNode->next = NULL;
    newNode->previous = NULL;
    return newNode;
}

void addFirst(string nama, int persentase)
{
    node *newNode = createNode(nama, persentase);

    if (head == NULL)
    {
        head = newNode;
        tail = newNode;
    }
    else
    {
        newNode->next = head;
        head->previous = newNode;
        head = newNode;
    }

    nodeSize++;
}

void addLast(string nama, int persentase)
{
    node *newNode = createNode(nama, persentase);

    if (tail == NULL)
    {
        head = newNode;
        tail = newNode;
    }
    else
    {
        tail->next = newNode;
        newNode->previous = tail;
        tail = newNode;
    }

    nodeSize++;
}

void deleteFirst()
{
    if (head == NULL)
    {
        // List kosong
    }
    else if (head->next == NULL)
    {
        // List hanya ada 1
        node *toDelete = head;
        head = NULL;
        tail = NULL;
        delete toDelete;

        nodeSize--;
    }
    else
    {
        // List lebih dari 1
        node *toDelete = head;
        head = head->next;
        head->previous = NULL;
        delete toDelete;

        nodeSize--;
    }
}

void deleteLast()
{
    if (tail == NULL)
    {
        // List kosong
    }
    else if (tail->previous == NULL)
    {
        // List hanya ada 1
        node *toDelete = tail;
        head = NULL;
        tail = NULL;
        delete toDelete;

        nodeSize--;
    }
    else
    {
        // List lebih dari 1
        node *toDelete = tail;
        tail = tail->previous;
        tail->next = NULL;
        delete toDelete;

        nodeSize--;
    }
}

void removeByKey(string key)
{
    if (head != NULL)
    {
        node *pointer = head;
        while (pointer != NULL)
        {
            if (pointer->nama == key)
            {
                string endedNama = pointer->nama;

                if (pointer == head)
                {
                    deleteFirst();
                }
                else if (pointer == tail)
                {
                    deleteLast();
                }
                else
                {
                    pointer->previous->next = pointer->next;
                    pointer->next->previous = pointer->previous;
                    delete pointer;
                }

                addLast(endedNama, 0);

                break;
            }
            pointer = pointer->next;
        }
    }
}

int getPercentage()
{
    if (head != NULL)
    {
        int persentase = 0;
        node *pointer = head;
        while (pointer != NULL)
        {
            persentase += pointer->persentase;
            pointer = pointer->next;
        }
        return persentase;
    }
    else
    {
        return 0;
    }
}

void printList()
{
    int remaining = 100;

    if (head != NULL)
    {
        node *pointer = head;
        while (pointer != NULL)
        {
            cout << pointer->nama << " (" << pointer->persentase << "%)" << endl;
            remaining -= pointer->persentase;
            pointer = pointer->next;
        }
    }

    cout << "used: " << 100 - remaining << "%" << endl;
    cout << "free: " << remaining << "%" << endl;
}

int main()
{

    int jumlahOperasi;
    cin >> jumlahOperasi;

    for (int i = 0; i < jumlahOperasi; i++)
    {
        string kunci;
        string nama;
        cin >> kunci;
        getline(cin, nama);
        if (nama.substr(0, 1) == " ")
        {
            nama = nama.substr(1, nama.length());
        }
        if (kunci == "add")
        {
            int persentase;
            cin >> persentase;
            addLast(nama, persentase);
        }
        else if (kunci == "end")
        {
            removeByKey(nama);
        }
    }

    if (getPercentage() > 100)
    {
        cout << "pc stop working";
    }
    else
    {
        printList();
    }

    return 0;
}