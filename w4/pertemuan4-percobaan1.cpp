//Percobaan Pertama: Memahami Node yang digunakan pada Double Linked List
#include <cstdlib>
#include <iostream>
#include <conio.h>

using namespace std;

struct node {
   //bagian data 
    char data;
   //pointer ke node selanjutnya
    struct node *next; 
    struct node *prev;
};
typedef struct node node;
node *head, *tail;

int main(){
    head = (node *)  malloc(sizeof(node));
    head->data = 'A';
    head->next = head->prev = NULL;
    cout << "Data:" << head->data << endl;
    cout << "Pointer next:" << head->next << endl;
    cout << "Pointer prev:" << head->prev << endl;
    getch();    
    return EXIT_SUCCESS;
}