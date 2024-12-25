#include <iostream>
using namespace std;

struct node
{
    int data; // data dari node
    struct node *next; // alamat node selanjutnya
};

node *head = NULL, *tail= NULL; //membuat head dan tail

void print(){ // Membuat fungsi print
    int index = 0; //Mendeklarasikan int index untukk indexing
    node *temp = head; // 
    while (temp != NULL)//apabila alamat head tidak kosong maka cetak data
    {
        cout << "data ke-"<<index<<" = " << temp->data << endl;
        temp = temp->next;
        index++;
    }
    
}

void insertfront(int n){ //membuat fungsi instert front
    node *newnode = new node;// membuat node baru
    newnode->data = n; //Memasukkan data ke node baru
    if (tail == NULL) // mengecek apakah linked listnya kosong
    {
        tail = newnode; //Apabila kosong data baru kita jadikan tail
    }else{
        newnode->next = head; //node baru akan merujuk ke head lama
    }
    head = newnode; //kita menjadikan node baru sebagai head
}
void insertback (int n){
    node *newnode = new node; // node baru
    newnode->data = n; // masukin data
    if (head == NULL) // mengecek apakah linked list kosong
    {
        head = newnode; //apabila kosong node baru dijadikan head 
    }else{
        tail->next = newnode; // apabila tidak maka tail sebelumnya akan merujuk pada node baru
    }
    tail = newnode; //node baru kita jadikan tail
}

void insertat(int n, int index){//Fungsi untuk menyisipkan data ke linked list
    if (head == NULL || index == 0)//Memeriksa apakah linked list kosong atau index yang kita masukkan = 0
    {
        insertfront(n); //Apabila iya maka masuk ke fungsi insert front
    }else{
        node *temp = head;//membuat node sementara bernama temp dan dimulai dari head
        for (int i = 1; i < index; i++)//Melakukan perulangan untuk menjalankan node temp
        {
            temp = temp->next;//Menjalankan node temp sampai index tujuan
            if (temp == tail)//memriksa apabila temp sudah mencapai ujung
            {
                insertback(n); //jika iya sama saja dengan fungsi insertback
                return;
            }
        }
        node *newnode = new node; // node baru
        newnode->data = n; // masukin data
        newnode->next = temp->next;//mengisi alamat next pada node baru dengan alamat next pada node temp 
        temp->next = newnode;//mengganti alamat next pada node temp dengan alamat newnode
        
    }

}

void removelast(){
    node *temp = head; //membuat node sementara bernama temp dan dimulai dari head
    while (temp->next != tail) // selama alamat next pada temp tidak mencapai tail maka temp akan terus berjalan
    {
        temp = temp->next;
    }
    delete tail; // Hapus tail yang lama
    tail = temp; // Menjadikan temp tail baru
    tail->next = NULL; // Menghapus nilai next pada tail yang baru
    
}

void removefirst(){ // Fungsi untuk menghapus data pertama
    node *temp = head->next; //membuat node sementara bernama temp dan dimulai dari head
    delete head; //hapus head lama
    head = temp; // menjadikan temp head baru
}

void removeat(int index){ // Menghapus data berdasarkan index
    if (index == 0)//Apabila index yang ingin dihapus adalah 0 maka sama saja dengan remove first
    {
        removefirst();
        return;
    }
    node *temp = new node; //membuat node sementara bernama temp
    node *temp2 = new node; //membuat node sementara bernama temp2
    for (int i = 1; i < index; i++)//Membbuat perulangan untuk menjalankan temp
    {
        temp = temp->next;
        if (temp == tail) // Apabila temp ternyata sampai tail maka sama saja dengna remove last
        {
            removelast();
            return;
        }
        
    }
    temp2 = temp->next; //Menaruh temp2 setelah tamp
    temp->next = temp->next->next; // Mengganti alamat pada next temp1 dengan alamat data setalahnya
    delete temp2; // Mengahpus temp2 
    
}

int front(){ //melihat data pertama
    return head->data;
}

int back(){ //melihat data terkahir
    return tail->data;
}

int lookat(int index){//Melihat data berdasarkan index
    if (head == NULL) // jika linked list ternyata kosong, maka akan menampilkan error
    {
        cout<<"ERROR"<< endl;
        return -1;
    }
    else{
        node *temp = head; // membuat node temp dan ditaruh di head
        for (int i = 0; i < index; i++)//melakukan perulangan untuk menjalankan temp
        {
            temp = temp->next;
            if (temp == NULL)// jika index yang dicari ternyata tidak ada, maka akan menampilkan error
            {
                cout << "ERRORR"<< endl;
                return -1;
            }
            
        }
        return temp->data; //Mengembalikan nilai data yang ada pada index yang kita inginikan
        
    }
    
}

int main(){
    insertback(12);
    insertback(13);
    insertback(14);
    insertback(15);
    insertfront(1);
    insertfront(2);
    insertfront(3);
    print();
}