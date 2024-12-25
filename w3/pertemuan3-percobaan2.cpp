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

void AddLast(char item){ // Add node after tail
    struct node *pNew;
    pNew = (node*) malloc(sizeof(node));
    pNew->data = item;
    if(head==NULL){
        head = pNew;
    }
    else{
        tail->next = pNew;
    }
    tail = pNew;
}

void AddFirst(char item){ // Add node before head
    struct node *pNew;
    pNew = (node*) malloc(sizeof(node));
    pNew->data = item;
    if(head==NULL){
        tail = pNew;
    }
    else{
        pNew->next = head;
    }
    head = pNew;
}


//TES 1
int main()
{
    head=tail=NULL;
    AddFirst('A');
    cout << "head : " << head->data <<endl;
    cout << "tail : " << tail->data <<endl;
    AddFirst('B');
    cout << "head : " << head->data <<endl;
    cout << "tail : " << tail->data <<endl;
    AddFirst ('C');
    cout << "head : " << head->data <<endl;
    cout << "tail : " << tail->data <<endl;
    AddFirst ('D');
    cout << "head : " << head->data <<endl;
    cout << "tail : " << tail->data <<endl;

    getch();
    return EXIT_SUCCESS;
}


/*
//TES 2
int main()
{
    head=tail=NULL;
    AddLast ('A');
    cout << "head : " << head->data <<endl;
    cout << "tail : " << tail->data <<endl;
    AddLast ('B');
    cout << "head : " << head->data <<endl;
    cout << "tail : " << tail->data <<endl;
    AddLast ('C');
    cout << "head : " << head->data <<endl;
    cout << "tail : " << tail->data <<endl;
    AddLast ('D');
    cout << "head : " << head->data <<endl;
    cout << "tail : " << tail->data <<endl;

    getch();
    return EXIT_SUCCESS;
}
*/