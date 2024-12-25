#include <iostream> //memanggil library iostream untuk input dan output
using namespace std; //menggunakan standard libarary untuk memudahkan penulisan seperti std::cout

struct node //membuat struct dengan nama node
{
    int data; //variabel dengan nama data yang akan disimpan di node
    node *next; //pointer yang akan menunjuk node selanjutnya
};

struct csll //membuat struct dengan nama csll
{
    node *tail = NULL, *head = NULL; //mendeklarasikan pointer head dan tail kosong dengan NULL

    bool isEmpty() //fungsi isEmpty untuk mengecek isi dari linked list
    {
        return (head == NULL and tail == NULL) ? 1 : 0; //mengecek isi linked list, jika linked list masih kosong akan bernilai 1 dan jika sudah ada isinya bernilai 0
    }

    void addFront(int data) //fungsi addFront untuk menambah data di depan
    {
        node *newNode = new node; //membuat newnode
        newNode->data = data; //memasukkan data ke newnode 
        newNode->next = newNode; //pointer next pada node newnode menunjuk dirinya sendiri

        if (isEmpty()) //mengecek apakah linked list kosong atau tidak
        {
            head = tail = newNode; //apabila linked list kosong maka head dan tail menunjuk ke newnode
        }
        else //jika tidak
        {
            newNode->next = head; //pointer next pada newnode akan menunjuk head
            head = newNode; //menjadikan newnode menjadi head
            tail->next = head; //pointer next pada tail menunjuk ke head
        }
    }

    void addBack(int data) //fungsi addBack untuk menambah data di belakang
    {
        node *newNode = new node; //membuat newnode
        newNode->data = data;  //memasukkan data ke newnode
        newNode->next = newNode; //pointer next pada node newnode menunjuk dirinya sendiri

        if (isEmpty()) //mengecek apakah linked list kosong atau tidak
        {
            head = tail = newNode; //apabila linked list kosong maka head dan tail menunjuk ke newnode
        }
        else //jika tidak
        {
            newNode->next = head; //pointer next pada newnode akan menunjuk head
            tail->next = newNode; //pointer next pada tail akan menunjuk ke newnode
            tail = newNode; //menjadikan newnode menjadi tail
        }
    }

    void removeFirst() //fungsi removeFirst untuk menghapus data paling depan
    {
        if (!isEmpty()) //mengecek apakah linked list kosong atau tidak
        {
            if (tail == head) //mengecek apakah head = tail (list hanya ada 1)
            {
                tail = head = NULL; //tail dan head menunjuk ke NULL
                return;
            }
			//jika list lebih dari 1 maka :
            node *temp = head; //deklarasi pointer temp yang menunjuk ke head

            tail->next = temp->next; //pointer next pada tail menunjuk ke node setelah temp
            head = tail->next; //menjadikan node setelah tail menjadi head

            delete temp; //menghapus temp
        }
    }

    void print() //fungsi print untuk menampilkan list
    {
        if (!isEmpty()) //mengecek apakah linked list kosong atau tidak
        {
            node *temp = tail->next; //deklarasi pointer temp yang menunjuk ke node setelah tail

            do //melakukan looping menggunakan do while
            {
                cout << temp->data << " "; //menampilkan data yang ditunjuk temp
                temp = temp->next; //menjadikan node setelah temp menjadi temp
            } while (temp != head); //looping dijalankan ketika temp tidak sama dengan head

            cout << endl; //memberi jarak 1 baris
        }
        else //jika kosong
        {
            cout << "List Kosong" << endl; //menampilkan "List Kosong"
        }
    }

    void removeLast() //fungsi removeLast untuk menghapus data paling akhir
    {
        if (!isEmpty()) //mengecek apakah linked list kosong atau tidak
        {
            if (tail == head) //mengecek apakah head = tail (list hanya ada 1)
            {
                tail = head = NULL; //tail dan head menunjuk ke NULL
                return;
            }

            node *temp = head; //deklarasi pointer bernama temp yang menunjuk ke head

            do //melakukan looping menggunakan do while
            {
                temp = temp->next; //menjadikan node setelah temp menjadi temp
            } while (temp->next != tail); //looping dijalankan ketika temp tidak sama dengan tail
            temp->next = tail->next; //memindahkan pointer next pada temp ke node setelah tail
            tail = temp; //menjadikan temp menjadi tail
        }
    }

    void remove(int data) //fungsi remove untuk menghapus data
    {
        if (data == head->data) //mengecek apakah data sama dengan data pada head
        {
            removeFirst(); //menjalankan fungsi removeFirst karena sama saja dengan menghapus data pertama
        }

        if (data == tail->data) //mengecek apakah data sama dengan data pada tail
        {
            removeLast(); //menjalankan fungsi removeLast karena sama saja dengan menghapus data terakhir
        }

        if (!isEmpty()) //mengecek apakah linked list kosong atau tidak
        {
            node *temp = head, *del; //deklarasi pointer del dan temp, pointer temp akan menunjuk ke head

            do //melakukan looping menggunakan do while
            {
                if (temp->next->data == data) //mengecek apakah data yang ada di node setelah temp sama dengan data yang ingin dihapus
                {
                    del = temp->next; //pointer del menunjuk pada node setelah temp
                    temp->next = del->next; //pointer next pada temp menunjuk ke node setelah del
                    delete del; //menghapus del
                }
                temp = temp->next; //menjadikan node setelah temp menjadi temp
            } while (temp != head); //looping dijalankan ketika temp tidak sama dengan head
        }
    }
};

int main() //fungsi main
{
    csll l1; //deklarasi struct
    for (int i = 0; i < 5; i++) //melakukan looping 5x
    {
        l1.addBack(i * 3); //menambah data dibelakang
        l1.addFront(i * 3); //menambah data didepan 
    }
    l1.print(); //menampilkan isi dari linked list
    l1.remove(6); //menghapus data yang bernilai 6 pada linked list
    l1.print(); //menampilkan isi dari linked list
    l1.remove(9); //menghapus data yang bernilai 9 pada linked list
    l1.print(); //menampilkan isi dari linked list
    l1.remove(100); //menghapus data yang bernilai 100 pada linked list
    l1.print(); //menampilkan isi dari linked list
    l1.remove(12); //menghapus data yang bernilai 12 pada linked list
    l1.print(); //menampilkan isi dari linked list
}