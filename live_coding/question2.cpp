#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

struct node{
    int data;
    node *next;
    node *previous;
};

node *head, *tail;
int size = 0;

node *create(int input){
    node *newNode = new node;
    newNode->data = input;
    newNode->next = NULL;
    newNode->previous = NULL;
    return newNode;
}

void insertfront(int input){
    node *newNode = create(input);
    if (head == NULL){
        head = newNode;
        tail = newNode;
    }
    else{
        newNode->next = head;
        head->previous = newNode;
        head = newNode;
    }
    size++;
}

void insertlast(int input){
    node *newNode = create(input);
    if (tail == NULL){
        head = newNode;
        tail = newNode;
    }
    else{
        tail->next = newNode;
        newNode->previous = tail;
        tail = newNode;
    }
    size++;
}

void removefront(){
    if (head == NULL){

    }
    else if (head->next == NULL){
        node *hapus = head;
        head = NULL;
        tail = NULL;
        delete hapus;
        size--;
    }
    else{
        node *hapus = head;
        head = head->next;
        head->previous = NULL;
        delete hapus;
        size--;
    }
}

void removelast(){
    if (tail == NULL){
        
    }
    else if (tail->previous == NULL){
        node *hapus = tail;
        head = NULL;
        tail = NULL;
        delete hapus;
        size--;
    }
    else{
        node *hapus = tail;
        tail = tail->previous;
        tail->next = NULL;
        delete hapus;
        size--;
    }
}

void insertindex(int input, int index){
    if (index > 0 && index < size){
        node *newNode = create(input);
        node *pointer = head;
        int counter = 0;
        while (counter < index){
            pointer = pointer->next;
            counter++;
        }
        newNode->previous = pointer;
        newNode->next = pointer->next;
        if (pointer->next != NULL){
            pointer->next->previous = newNode;
        }
        pointer->next = newNode;
        size++;
    }
}

void removedata(int data){
    if (head != NULL){
        node *pointer = head;
        while (pointer->next != NULL){
            if (pointer->data == data){
                if (pointer == head){
                    removefront();
                }
                else if (pointer == tail){
                    removelast();
                }
                else{
                    pointer->previous->next = pointer->next;
                    pointer->next->previous = pointer->previous;
                    delete pointer;
                }
                break;
            }
            pointer = pointer->next;
        }
    }
}

void print(){
    node *headpointer = head;
    while (headpointer != NULL){
        cout << headpointer->data << " ";
        headpointer = headpointer->next;
    }
    cout << endl;
    node *tailpointer = tail;
    while (tailpointer != NULL){
        cout << tailpointer->data << " ";
        tailpointer = tailpointer->previous;
    }
}

int main() {
    int jumlahData;
    cin >> jumlahData;
    for (int i = 0; i < jumlahData; i++){
        int input;
        cin >> input;
        insertlast(input);
    }
    int jumlahRemove;
    cin >> jumlahRemove;
    for (int i = 0; i < jumlahRemove; i++){
        int inputRemove;
        cin >> inputRemove;
        removedata(inputRemove);
    }
    print();

    return 0;
}