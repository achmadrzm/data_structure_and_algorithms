#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

struct node {
    int data;
    struct node *next;
};

node *head = NULL, *tail = NULL;

void InsertLast(int x){
    struct node *pNew = new node;
    pNew->data = x;
    if (head == NULL){
        head= pNew;
    }
    else {
        tail->next = pNew;
    }
    tail=pNew;
}

void insertIndex(int index, int x){
    node *baru = new node;
    baru->data=x;
    baru->next = NULL;
    if(index==0){
        baru->next=head;
        head = baru;
    }
    else{
        node *temp = head;
        for(int i=0; i<index-1 && temp!=NULL; i++){
            temp = temp->next;
        }
        baru->next = temp->next;
        temp->next = baru;
        if(temp==tail){
            tail  =baru;
        }
    }
}

void print()
{
    if (head == NULL) {
        cout << "Empty" << endl;
        return;
    }
    node *temp = head;
    while(temp != NULL){
        cout << temp->data << " ";
        temp = temp->next;
                
    }
}

int main()
{
    int n,m,N,i,M;
    cin >> n;
    for(int i=0; i<n; i++) {
        cin >> m;
        InsertLast(m);
    }
    cin >> N;
    for(int a=0; a<N; a++) {
        cin >> i;
        cin >> M;
        insertIndex(i,M);
    }
    print();
    return 0;
}