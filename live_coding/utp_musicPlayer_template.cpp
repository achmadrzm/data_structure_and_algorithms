#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

struct song {
    string title;
    string artist;
    song *next=NULL;
    song *prev=NULL;
};

struct playlist {
    string nama;
    song *heads = NULL;
    song *tails = NULL;
    playlist *next = NULL;
    playlist *prev = NULL;
};

void addFront(int data) {
    song *newNode = new song; 
    newNode->data = data; 
    newNode->prev = newNode; 
    newNode->next = newNode; 

    if (isEmpty()) {
        head = tail = newNode;
    }
    else {
        newNode->next = head;
        newNode->prev = tail;
        head->prev = newNode;
        tail->next = newNode;
        head = newNode;
    }
}

void addBack(int data) {
    song *newNode = new song; 
    newNode->data = data; 
    newNode->prev = newNode; 
    newNode->next = newNode; 

    if (isEmpty()) {
        head = tail = newNode;
    }
    else {
        newNode->prev = tail;
        newNode->next = head;
        tail->next = newNode;
        head->prev = newNode;
        tail = newNode;
    }
}

void removeFirst() {
    if (!isEmpty()) {
        if (tail == head) {
            tail = head = NULL;
            return;
        }

        song *temp = head;

        tail->next = temp->next;
        temp->next->prev = tail;
        head = tail->next;

        delete temp;
    }
}

void removeLast() {
    if (!isEmpty()) {
        if (tail == head) {
            tail = head = NULL;
            return;
        }

        song *temp = tail;

        temp->prev->next = head;
        head->prev = temp->prev;
        tail = temp->prev;

        delete temp;
    }
}

void remove(int data) {
    if (data == head->data) {
        removeFirst();
    }

    if (data == tail->data) {
        removeLast();
    }

    if (!isEmpty()) {
        song *temp = head, *del;

        do {
            if (temp->next->data == data) {
                del = temp->next;
                temp->next = del->next;
                del->next->prev = temp;
                delete del;
            }
            temp = temp->next;
        } while (temp != head);
    }
}

void printMaju() {
    if (!isEmpty()) {
        song *temp = head;

        do {
            cout << temp->data << " ";
            temp = temp->next;
        } while (temp != head);

            cout << endl;
    }
    else {
        cout << "List Kosong" << endl;
    }
}

void printmundur() {
    song *temp = tail;
    do {
        cout << temp->data << " ";
        temp = temp->prev;
    } while (temp->prev !=tail->prev);
    cout << endl; 
}

int main() {
    
    
    return 0;
}