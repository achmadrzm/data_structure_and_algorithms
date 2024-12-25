#include <stdlib.h>
#include <iostream>
#include <conio.h>

using namespace std;

struct node
{
    string nim;
    string nama;
    double ipk;
    node *next=NULL;
};

struct mahasiswa
{
    node *head = NULL;
    node *tail = NULL;
    node *current = NULL;
    void AddLast(node *inputx);
    void disp();
};

void mahasiswa::AddLast(node *inputx)
{
    if(head == NULL)
    {
        head = inputx;
    }
    else
    {
        tail->next = inputx;
    }
    tail = inputx;
}

void mahasiswa :: disp()
{
    node *akhir = NULL;
    bool urutan = 1;
    while(akhir != head)
    {
        node *temp, *swap1;
        swap1 = head;
        while (swap1->next != akhir)
        {
            if (swap1->ipk > swap1->next->ipk)
            {
                node *swap2 = swap1->next;
                swap1->next = swap2->next;
                swap2->next = swap1;
                if(swap1 == head)
                {
                    head = swap2;
                    swap1 = swap2;
                }
                else
                {
                    swap1 = swap2;
                    temp->next = swap2;
                }
            }
            temp = swap1;
            swap1 = swap1->next;
        }
        akhir = swap1;
    }
    current = head;
    cout << endl;
    cout << "Output : " << endl;
    do
    {
        cout << endl;
        cout << "Nama Mahasiswa : " << current->nama <<
        endl;
        cout << "NIM Mahasiswa : " << current->nim <<
        endl;
        cout << "IPK Mahasiswa : " << current->ipk;
        current = current->next;
    }
    while (current != NULL);
}

int main(){
    mahasiswa *arrange = new mahasiswa;
    node *inputx;
    int pilihan;
    while (pilihan != 3)
    {
        cout << "Pilihan Menu : " << endl;
        cout << "1. Input Data Mahasiswa" << endl;
        cout << "2. Tampilkan Data Mahasiswa" << endl;
        cout << "3. Exit" << endl;
        cout << "Pilihan Anda : ";
        cin >> pilihan;
        cin.get();
        switch(pilihan)
        {
            case 1:
            inputx = new node;
            cout << endl;
            cout << "Masukan Nama Mahasiswa : ";
            getline(cin, inputx->nama);
            cout << "Masukan NIM Mahasiswa : ";
            getline(cin, inputx->nim);
            cout << "Masukan IPK Mahasiswa : ";
            cin >> inputx->ipk;
            arrange->AddLast(inputx);
            cout << endl;
            cout << "Data telah ditambahkan\n";
            getch();
            break;

            case 2:
            arrange->disp();
            getch();
            break;
            
            case 3:
            return 0;
            default:
            cout << "tidak tersedia";
        }
    }
    return EXIT_SUCCESS;
}