#include<iostream>
#include  <bits/stdc++.h>
#include <string>
using namespace std;
struct node 
{
    int data;
    string apk;
    node *next=NULL;

};
    node *head = NULL, *tail = NULL; 

void print(){

    node *temp = head; //membuat variabel sementara
    while (temp != NULL)//apabila alamat head tidak kosong maka cetak angka 
    {
        cout << temp->apk<<" ("  << temp->data << "%)"<< endl;//print
        temp = temp->next;//alamat temp diganti dengan alamat selanjutnya
    }
    
}

void sort() {
    bool sorted = false;
    while (!sorted) {
        sorted = true;
        node* temp = head;
        while (temp->next != NULL) {
            if (temp->data < temp->next->data) {
                sorted = false;
                int tempData = temp->data;
                string tempApk = temp->apk;
                temp->data = temp->next->data;
                temp->apk = temp->next->apk;
                temp->next->data = tempData;
                temp->next->apk = tempApk;
            }
            temp = temp->next;
        }
    }
}
void insertfront(int n, string apk)
{
node *newnode = new node;//mengalokasikan memori untuk node baru = malloc
newnode->data = n;//memasukkan angka ke node baru
newnode->apk = apk;
    if (tail == NULL)//apabila head masih kosong
    {
        tail = newnode;//head menunjuk ke node baru
    }else
    {
        newnode->next = head;//memasukkan alamat head ke node baru  
    }

head = newnode;//menunjuk alamat node baru dengan head
// cout << head->data<< endl;
}

void insertback(int n, string apk)
{
    node *newnode = new node;//mengalokasikan memori untuk node baru
    newnode->data = n;//memasukkan angka ke node baru
    newnode->apk = apk;
    if (head == NULL)//apabila head masih kosong
    {
        head = newnode;//head menunjuk ke node baru
    }else{
    
    tail->next = newnode;//menunjuk alamat tail ke alamat node baru

    }

    tail = newnode;//menjadikan node baru sebagai data terakhir/tail
// cout << head->data<< endl;
}

void removefirst(){
    if(head == tail){
        head = tail = NULL;
    }else{
    node *temp = head->next;
    delete head;
    head = temp;
    }
}

    void removeat(string aplikasi)
    {
            node *temp = head;

            do
            {
                if (temp->apk == aplikasi)
                {
                    removefirst();
                    insertback(0,aplikasi);
                }
                if (tail->apk == aplikasi)
                {
                    tail->data = 0;
                    break;
                }
                
                
                if (temp->next->apk == aplikasi)
                {
                    temp->next = temp->next->next;
                    // cout << "nama apk " << aplikasi;
                    insertback(0, aplikasi);
                    break;
                }
                temp = temp->next;                
            } while (temp != tail);
            
    }

int main(){
    int n;
    int memori;
    string command, aplikasi;
    cin >> n;
    for(int i=0;i<n;i++){
        cin >> command;
        cin.ignore();
        getline (cin, aplikasi);
        if(command == "add")
        {
            cin >> memori;
            insertfront(memori, aplikasi);
        }
        
        if(command=="end"){

            removeat(aplikasi);

        }
        
    }
    int sisa = 100;
    int guna = 0;
    node* temp = head;
    while (temp != NULL)
    {
        sisa -= temp->data;
        guna += temp->data;
        temp = temp->next;
        if(sisa < 0 || guna > 100)
        {
        cout << "pc stop working";
        return 0;
        }

        
        
    }
    sort();
    print();
    cout << "used: " << guna <<"%"<< endl;
    cout << "free: " << sisa <<"%"<< endl;
    
}

