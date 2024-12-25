#include <iostream>
#include <cstdlib>
#include <cstring>
using namespace std;

struct node{
    string nim;
    string nama;
    double ipk;
    node *next;
    node *prev;    
};
node *head = NULL, *tail= NULL;

void addFirst(string nim, string nama, double ipk){
    node *newnode = new node;
    newnode->nim = nim;
    newnode->nama = nama;
    newnode->ipk = ipk;
    if(head==NULL){
        head = tail = newnode;
        newnode->prev = NULL;
        newnode->next = NULL;
    }
    else{
        newnode->next = head;
        head->prev = newnode;
        head = newnode;
        newnode->prev = NULL;
    }
}

void addLast(string nim, string nama, double ipk){
    node *newnode = new node;
    newnode->nim = nim;
    newnode->nama = nama;
    newnode->ipk = ipk;
    if(head==NULL){
        head = tail = newnode;
        newnode->prev = NULL;
        newnode->next = NULL;
    }
    else{
        newnode->prev = tail;
        tail->next = newnode;
        tail = newnode;
        newnode->next = NULL;
    }
}

void addAtIndex(int index, string nim, string nama, double ipk){
    node *newnode = new node;
    newnode->nim = nim;
    newnode->nama = nama;
    newnode->ipk = ipk;
    if(index==0){
        if(head==NULL){
            head = tail = newnode;
            newnode->prev = NULL;
            newnode->next = NULL;
        }
        else{
            newnode->prev = tail;
            tail->next = newnode;
            tail = newnode;
            newnode->next = NULL;
        }
    }
    else{
        node *temp = head;
        for(int i=0; i<index && temp!=NULL; i++){
            temp = temp->next;
        }
        newnode->next = temp->next;
        newnode->prev = temp;
        temp->next = newnode;
        temp = newnode->next;
        temp->prev = newnode;
    }
}

void removeFirst(){
    node *newnode = head;
    if(head==NULL){
        head = tail = NULL;
    }
    else if(head==tail){
        delete newnode;
        head = tail = NULL;
    }
    else{
        head = head->next;
        head->prev = NULL;
        delete newnode;
    }
}

void removeLast(){
    node *newnode = tail;
    if(head==NULL){
        head = tail = NULL;
    }
    else if(head==tail){
        delete newnode;
        head = tail = NULL;
    }
    else{
        newnode = tail->prev;
        newnode->next = NULL;
        delete tail;
        tail = newnode;
    }
}

void removeAtIndex(int index){
    node *newnode = head;
    node *temp = head;
    if(index==0){
        head = head->next;
        head->prev = NULL;
        delete newnode;
    }
    else{
        for(int i = 0; i<index && newnode!=NULL && temp!=NULL; i++){
            temp = temp->next;
            newnode = newnode->next;
        }
        newnode = newnode->prev;
        temp = temp->next;
        delete newnode->next;
        newnode->next = temp;
        temp->prev = newnode;
    }
}

void accesFront(){
    cout << "Head berisi: " << endl;
    cout << head->nim << ", " << head->nama << ", " << head->ipk << endl;
}

void accesBack(){
    cout << "Tail berisi: " << endl;
    cout << tail->nim << ", " << tail->nama << ", " << tail->ipk << endl;
}

void accesAtIndex(int index){
    node *newnode = head;
    for(int i = 0; i<index && newnode!=NULL; i++){
        newnode = newnode->next;
    }
    cout << "Node pada indeks ke-" << index << " berisi: " << endl;
    cout << newnode->nim << ", " << newnode->nama << ", " << newnode->ipk << endl;
}

void insertFirst(string nim, string nama, double ipk){
    head->nim = nim;
    head->nama = nama;
    head->ipk = ipk;
}

void insertLast(string nim, string nama, double ipk){
    tail->nim = nim;
    tail->nama = nama;
    tail->ipk = ipk;
}

void insertAtIndex(int index, string nim, string nama, double ipk){
    node *newnode = head;
    for(int i = 0; i<index && newnode!=NULL; i++){
        newnode = newnode->next;
    }
    newnode->nim = nim;
    newnode->nama = nama;
    newnode->ipk = ipk;
}

void print(){
    node *newnode = head;
    cout << "Daftar mahasiswa: " << endl;
    while(newnode!=NULL){
        cout << newnode->nim << ", " << newnode->nama << ", " << newnode->ipk << endl;
        newnode = newnode->next;
    }
    cout << endl;
}

void sortAscending(){
    node *newnode = head;
    node *temp = head;
    temp = temp->next;
    string hold1, hold2;
    double hold3;
    for(int i = 0; i<10000; i++){
        newnode = head;
        temp = newnode->next;
        while(temp!=NULL){
            if(newnode->ipk > temp->ipk){
                hold1 = newnode->nim;
                hold2 = newnode->nama;
                hold3 = newnode->ipk;
                newnode->nim = temp->nim;
                newnode->nama = temp->nama;
                newnode->ipk = temp->ipk;
                temp->nim = hold1;
                temp->nama = hold2;
                temp->ipk = hold3;
            }
            newnode = newnode->next;
            temp = temp->next;
        }
    }
    cout << "Urutan mahasiswa dari IPK yang terkecil ke terbesar: " << endl;
    node *print = head;
    while(print!=NULL){
        cout << print->nim << ", " << print->nama << ", " << print->ipk << endl;
        print = print->next;
    }
    cout << endl;
}

void sortDescending(){
    node *newnode = head;
    node *temp = head;
    temp = temp->next;
    string hold1, hold2;
    double hold3;
    for(int i = 0; i<10000; i++){
        newnode = head;
        temp = newnode->next;
        while(temp!=NULL){
            if(newnode->ipk < temp->ipk){
                hold1 = newnode->nim;
                hold2 = newnode->nama;
                hold3 = newnode->ipk;
                newnode->nim = temp->nim;
                newnode->nama = temp->nama;
                newnode->ipk = temp->ipk;
                temp->nim = hold1;
                temp->nama = hold2;
                temp->ipk = hold3;
            }
            newnode = newnode->next;
            temp = temp->next;
        }
    }
    cout << "Urutan mahasiswa dari IPK yang terbesar ke terkecil: " << endl;
    node *print = head;
    while(print!=NULL){
        cout << print->nim << ", " << print->nama << ", " << print->ipk << endl;
        print = print->next;
    }
    cout << endl;
}

int main(){
        addFirst("2201", "Abi", 4.0);
        addFirst("2202", "Budi", 2.1);
        addLast("2203", "Christ", 3.5);
        addLast("2204", "Dani", 3.7);
        addFirst("2205", "Erik", 3.0);
        addLast("2206", "Farza", 3.9);
        addLast("2207", "Gita", 2.9);
        print();
        sortAscending();
        sortDescending();
        return 0;
}