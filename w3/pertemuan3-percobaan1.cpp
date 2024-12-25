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

int main()
{
    head = (node *)  malloc(sizeof(node));  
    head->data='A';
    head->next=NULL;
    cout << "Data:" << head->data << endl;
    cout << "Pointer:" << head->next << endl;

    getch();
    return EXIT_SUCCESS;
}