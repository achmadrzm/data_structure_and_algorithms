//100
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

struct Node {
    string name;
    int number;
    Node* prev;
    Node* next;
};

Node* circularList(int n, string nama[]) {
    Node* head = new Node;
    head->name = nama[0];
    head->number = 1;
    head->prev = nullptr;
    Node* current = head;

    for (int i = 1; i < n; i++) {
        Node* newNode = new Node;
        newNode->name = nama[i];
        newNode->number = i + 1;
        newNode->prev = current;
        current->next = newNode;
        current = newNode;
    }

    current->next = head;
    head->prev = current;

    return head;
}

Node* executed(Node* head, int k) {
    Node* current = head;
    while (current->next != current) {
        for (int i = 0; i < k - 1; i++) {
            current = current->next;
        }
        current->prev->next = current->next;
        current->next->prev = current->prev;
        Node* temp = current;
        current = current->next;    
        delete temp;
    }
    return current;
}

int main() {
    int n, k;
    cin >> n;

    string nama[n];
    cin.ignore();
    for (int i = 0; i < n; i++) {
        getline(cin, nama[i]);
    }

    cin >> k;

    Node* head = circularList(n, nama);
    Node* survivor = executed(head, k);

    cout << survivor->name << "(" << survivor->number << ")" << endl;

    return 0;
}