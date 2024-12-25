#include <iostream> //memanggil library iostream untuk input dan output
using namespace std; //menggunakan standard libarary untuk memudahkan penulisan seperti std::cout

struct node //membuat struct dengan nama node
{
    int data; //variabel dengan nama data yang akan disimpan di node
    node *next; //pointer yang akan menunjuk node selanjutnya
    node *prev; //pointer yang akan menunjuk node sebelumnya
};

struct cdll //membuat struct dengan nama cdll
{
    node *head = NULL, *tail = NULL; //mendeklarasikan pointer head dan tail kosong dengan NULL

    bool isEmpty() //fungsi isEmpty untuk mengecek isi dari linked list
    {
        return (tail == NULL and head == NULL) ? 1 : 0; //mengecek isi linked list, jika linked list masih kosong akan bernilai 1 dan jika sudah ada isinya bernilai 0
    }

    void addFront(int data) //fungsi addFront untuk menambah data di depan
    {
        node *newNode = new node; //membuat newnode
        newNode->data = data; //memasukkan data ke newnode  
        newNode->prev = newNode; //pointer prev pada node newnode menunjuk dirinya sendiri
        newNode->next = newNode; //pointer next pada node newnode menunjuk dirinya sendiri

        if (isEmpty()) //mengecek apakah linked list kosong atau tidak
        {
            head = tail = newNode; //apabila linked list kosong maka head dan tail menunjuk ke newnode
        }
        else //jika tidak
        {
            newNode->next = head; //pointer next pada newnode akan menunjuk head
            newNode->prev = tail; //pointer prev pada newnode akan menunjuk tail
            head->prev = newNode; //pointer prev pada head akan menunjuk ke newnode
            tail->next = newNode; //pointer next pada tail akan menunjuk ke newnode
            head = newNode; //menjadikan newnode menjadi head
        }
    }

    void addBack(int data) //fungsi addBack untuk menambah data di belakang
    {
        node *newNode = new node; //membuat newnode
        newNode->data = data; //memasukkan data ke newnode 
        newNode->prev = newNode; //pointer prev pada node newnode menunjuk dirinya sendiri
        newNode->next = newNode; //pointer next pada node newnode menunjuk dirinya sendiri

        if (isEmpty()) //mengecek apakah linked list kosong atau tidak
        {
            head = tail = newNode; //apabila linked list kosong maka head dan tail menunjuk ke newnode
        }
        else //jika tidak
        {
            newNode->prev = tail; //pointer prev pada newnode akan menunjuk tail
            newNode->next = head; //pointer next pada newnode akan menunjuk head
            tail->next = newNode; //pointer next pada tail akan menunjuk ke newnode
            head->prev = newNode; //pointer prev pada head akan menunjuk ke newnode
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
            temp->next->prev = tail; //pointer prev pada node setelah temp menunjuk ke tail
            head = tail->next; //menjadikan node setelah tail menjadi head

            delete temp; //menghapus temp
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
			//jika list lebih dari 1 maka :
            node *temp = tail; //deklarasi pointer bernama temp yang menunjuk ke tail

            temp->prev->next = head; //pointer next pada node sebelum temp menunjuk ke head
            head->prev = temp->prev; //pointer prev pada head menunjuk ke node sebelum temp
            tail = temp->prev; //menjadikan node sebelum temp menjadi tail

            delete temp; //menghapus temp
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

        if (!isEmpty()) //Mengecek apakah linked list kosong atau tidak
        {
            node *temp = head, *del; //deklarasi pointer del dan temp, pointer temp akan menunjuk ke head

            do //melakukan looping menggunakan do while
            {
                if (temp->next->data == data) //mengecek apakah data yang ada di node setelah temp sama dengan data yang ingin dihapus
                {
                    del = temp->next; //pointer del menunjuk pada node setelah temp
                    temp->next = del->next; //pointer next pada temp menunjuk ke node setelah del
                    del->next->prev = temp; //pointer prev pada node setelah del menunjuk ke temp
                    delete del; //menghapus del
                }
                temp = temp->next; //menjadikan node setelah temp menjadi temp
            } while (temp != head); //looping dijalankan ketika temp tidak sama dengan head
        }
    }

    void printMaju() //fungsi printMaju untuk menampilkan data dari head ke tail
    {
        if (!isEmpty()) //mengecek apakah linked list kosong atau tidak
        {
            node *temp = head; //deklarasi pointer temp menjadi head

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
    void printmundur(){ //fungsi printMundur untuk menampilkan data dari tail ke head

    node *temp = tail; //deklarasi pointer temp menjadi tail
    do //melakukan looping menggunakan do while
    {
        cout << temp->data << " "; //menampilkan data yang ditunjuk temp
        temp = temp->prev; //menjadikan node sebelum temp menjadi temp
    } while (temp->prev !=tail->prev); //looping dijalankan ketika node sebelum temp tidak sama dengan node sebelum tail
    cout << endl; //memberi jarak 1 baris
    
}
};

int main() //fungsi main
{
    cdll l1; //deklarasi struct
    for (int i = 0; i < 5; i++) //melakukan looping 5x
    {
        l1.addFront(i * 2); //Menambah data didepan
        l1.addBack(i * 2); //Menambah data dibelakang
    }
    
    l1.printMaju(); //menampilkan data dari head ke tail
    l1.removeFirst(); //menghapus data pertama
    l1.printMaju(); //menampilkan data dari head ke tail
    l1.printmundur(); //menampilkan data dari tail ke head
    l1.removeLast(); //menghapus data terakhir
    l1.printMaju(); //menampilkan data dari head ke tail
    l1.remove(6); //menghapus data yang bernilai 6 pada linked list
    l1.printMaju(); //menampilkan data dari head ke tail
}