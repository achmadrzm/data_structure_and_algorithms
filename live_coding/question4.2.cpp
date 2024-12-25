#include<iostream>
using namespace std;
struct node //membuat struct node
{
    int data;
    string apk;
    node *next=NULL;

};
    node *head = NULL, *tail = NULL, *head2 = NULL, *tail2 = NULL; 

void print(){

    node *temp = head; //membuat variabel sementara
    while (temp != NULL)//apabila alamat head tidak kosong maka cetak angka 
    {
        cout << temp->apk<< endl;//print
        temp = temp->next;//alamat temp diganti dengan alamat selanjutnya
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
void insertfront2(string apk)
{
node *newnode = new node;//mengalokasikan memori untuk node baru = malloc
newnode->apk = apk;
    if (tail2 == NULL)//apabila head masih kosong
    {
        tail2 = newnode;//head menunjuk ke node baru
    }else
    {
        newnode->next = head2;//memasukkan alamat head ke node baru  
    }

head2 = newnode;//menunjuk alamat node baru dengan head
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
    node *temp = head->next;
    delete head;
    head = temp;

}

string removelast(){
    node *temp = head;
    node *temp2 = tail;
    string temp3;
    if (tail == head)
    {
        temp3 = tail->apk;
        tail = head = NULL;
        return temp3;
    }
    
    while (temp->next !=tail )
    {
        temp = temp->next;
    }
    tail = temp;
    tail->next = NULL;

    return temp2->apk;

}

string front(){
    node *temp = head2;
    head2 = temp->next;
    return temp->apk;
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

int main()
{
    int n;
    string command;
    cin >> n;
    string cmd_sblm = "0";
    for(int i=0;i<n;i++)
    {
        cin >> command;
        if (command == "undo")
        {
            if (head == NULL)
            {
                continue;
            }
            
            insertfront2(removelast());
        }
        else if (command == "redo")
        {
            if (cmd_sblm == "0" || (cmd_sblm !="undo" && cmd_sblm != "redo") || head2 == NULL)
            {
                continue;
            }
            
            insertback(0,front());
        }
        else 
        {
            insertback(0, command);
        }
        cmd_sblm = command;
    }

    print();
}

