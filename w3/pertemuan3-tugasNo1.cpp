#include <iostream>
#include <cstdlib>
#include <conio.h>

using namespace std;

struct node
{
    string nim;
    string nama;
    double ipk;
    node *next = NULL;
};

struct mahasiswa
{
    node *head = NULL;
    node *tail = NULL;
    node *current = NULL;
    void addlast(node *inputx);
    void disp();
};

void mahasiswa :: addlast(node *inputx)
{
    if(head == NULL)
    {
        head = inputx;
    }
    else
    {
        tail->next = inputx;
        tail = inputx;
    }
}
void mahasiswa :: disp()
{
    current = head;
    cout << endl;
    cout << "Output : " << endl;
    do
    {
        cout << endl;
        cout << "Nama Mahasiswa : " << current->nama << endl;
        cout << "NIM Mahasiswa : " << current->nim << endl;
        cout << "IPK Mahasiswa : " << current->ipk;
        current = current->next;
    }
    while (current != NULL);
}

int main()
{
    mahasiswa *arrange = new mahasiswa;
    node *inputx;
    int pilihan;
    while (pilihan != 3)
    {
        cout << "Pilihan Menu : \n";
        cout << "1. Input Data Mahasiswa\n";
        cout << "2. Tampilkan Data Mahasiswa\n";
        cout << "3. Exit\n";
        cout << "Pilihan anda : ";
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
            arrange->addlast(inputx);
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