#include <cstdlib>
#include <iostream>
#include <conio.h>

using namespace std;

struct node{
   //bagian data
    char data;
   //pointer ke node selanjutnya
    struct node *next;
};
typedef struct node node;
node *head, *tail;

void print(){ // Menampilkan isi dari linked list (Pengaksesan)
    int index = 0; //Mendeklarasikan int index untukk indexing
    node *temp = head; //
    while (temp != NULL)//apabila alamat head tidak kosong maka cetak data
    {
        cout << "data ke-"<<index<<" = " << temp->data << endl;
        temp = temp->next;
        index++;
    }
}

void AddLast(char item){ // Penambahan data di akhir (penambahan)
    struct node *pNew;
    pNew = (node *)  malloc(sizeof(node));
    pNew->data = item;
    if (head == NULL){
        head= pNew;
    }
    else {
        tail->next = pNew;
    }
    tail=pNew;
    tail->next = NULL;
}

void AddFirst(char item){ // Penambahan data di awal (penambahan)
    struct node *pNew;
    pNew = (node *)  malloc(sizeof(node));
    pNew->data = item;
    if (head == NULL){
        tail= pNew;
    }
    else {
        pNew->next = head;
    }
    head=pNew;
}

void insertat(char item, int index){ //Fungsi untuk menyisipkan data ke linked list (Penyisipan)
    if (head == NULL || index == 0){ //Memeriksa apakah linked list kosong atau index yang kita masukkan = 0
        AddFirst(item); //Apabila iya maka masuk ke fungsi insert front
    }else{
        node *temp = head; //membuat node sementara bernama temp dan dimulai dari head
        for (int i = 1; i < index; i++){ //Melakukan perulangan untuk menjalankan node temp
            temp = temp->next; //Menjalankan node temp sampai index tujuan
            if (temp == tail){ //memriksa apabila temp sudah mencapai ujung
                AddLast(item); //jika iya sama saja dengan fungsi insertback
                return;
            }
        }
        node *pNew = (node *)  malloc(sizeof(node)); // node baru
        pNew->data = item; // masukin data
        pNew->next = temp->next; //mengisi alamat next pada node baru dengan alamat next pada node temp
        temp->next = pNew; //mengganti alamat next pada node temp dengan alamat newnode

    }
}

void deleteFirst(){ // Menghapus data pertama (head) (Penghapusan)
    if(head != NULL){
        node *del = head;
        head = head->next;
        delete del;
    }
}

void deleteLast(){ // Menghapus data terakhir (tail) (Penghapusan)
    if(head != NULL){ // mengecek apakah linked list ada isinya atau tidak
        if(head->next != NULL){ // mengecek apakah isi linked list lebih dari satu
            node *tmp = head;
            while(tmp->next->next != NULL){
                tmp = tmp->next;
            }
            node *del = tmp->next;
            tmp->next = NULL;
            delete del;
        }else{
            delete head;
            head = NULL;
        }
    }
}

void deleteat(int index){ //Menghapus data di index tertentu (Penghapusan)
    if(head != NULL){
        if(index == 0){
            deleteFirst();
        }
        node *temp = head;
        for(int i = 0; i < index-1; i++){
            if(temp->next == NULL){
                cout << "Index out of bounds\n";
                return;
            }
            temp = temp->next;
        }
        node *del = temp->next;
        temp->next = temp->next->next;
        delete del;
    }
}

void getnode(int index){ //Menampilkan isi index tertentu (Pencarian)
    node *temp = head;
    for(int i = 0; i < index; i++){
        if(temp->next == NULL){
            cout << "Index out of bounds\n";
            return;
        }
        temp = temp->next;
    }
    cout << "data ke-"<<index<<" = " << temp->data << endl;
}

int main(){
    head=tail=NULL;
    cout << "1. Penambahan" << endl;
    AddFirst('B'); // Penambahan data di awal
    AddFirst('A'); // Penambahan data di awal
    AddLast('C'); // Penambahan data di akhir
    AddLast('D'); // Penambahan data di akhir
    AddLast('E'); // Penambahan data di akhir
    print(); // Menampilkan isi linked list
    cout << endl;

    cout << "2. Penghapusan" << endl;
    deleteFirst(); // Penghapusan data di awal
    deleteLast(); // Penghapusan data di akhir
    deleteat(1); // Penghapusan data di index ke-1
    print(); // Menampilkan isi linked list
    cout << endl;

    cout << "3. Penyisipan" << endl;
    insertat('X', 1); // Penambahan data di index ke-1
    insertat('Y', 2); // Penambahan data di index ke-2
    insertat('Z', 3); // Penambahan data di index ke-3
    print(); // Menampilkan isi linked list
    cout << endl;

    cout << "4. Pencarian" << endl;
    getnode(0); // Menampilkan data index ke-0
    getnode(2); // Menampilkan data index ke-2
    getnode(4); // Menampilkan data index ke-4
    cout << endl;

    cout << "5. Pengaksesan" << endl;
    print(); // Menampilkan isi linked list

    getch();
    return EXIT_SUCCESS;
}