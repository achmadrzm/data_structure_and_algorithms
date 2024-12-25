#include <iostream> //memanggil library iostream untuk input dan output
using namespace std; //menggunakan standard libarary untuk memudahkan penulisan seperti std::cout

struct node //membuat struct dengan nama node
{
    int data; //variabel dengan nama data yang akan disimpan di node
    node *next= NULL; //pointer ke node selanjutnya, awalnya diinisialisasi dengan NULL
};

struct stack //membuat struct dengan nama stack
{
    node *top = NULL; //pointer top of stack, awalnya diinisialisasi dengan NULL

    bool empty() //fungsi untuk memeriksa apakah stack kosong
    {

        return top == NULL; //mengembalikan nilai top = NULL, jika top berisi NULL, maka stack kosong
    }

    void push(int data) //fungsi void untuk menambahkan elemen kedalam stack
    {
        node *newNode = new node; //membuat node baru
        newNode->data = data; //memasukkan data ke node baru

        if (!empty()) //jika stack tidak kosong
        {
            newNode->next = top; //pointer next node baru diarahkan ke top
        }
        top = newNode; //pointer top diarahkan ke node baru
    }

    int pop() //fungsi untuk mengeluarkan data dari stack
    {
        if (!empty()) //jika stack tidak kosong
        {
            int data = top->data; //ambil data pada node yang paling atas
            top = top->next; //pointer top diarahkan ke node selanjutnya(dibawahnya)
            return data; //kembalikan data yang diambil
        }

        return -1; //jika stack kosong, kembalikan nilai -1
    }

    void print() //fungsi untuk mencetak isi stack
    {
        if (!empty()) //jika stack tidak kosong
        {
            node *temp = top; //inisialisasi pointer temp dengan top
            do
            {
                cout << temp->data << " "; //cetak nilai data pada node
                temp = temp->next; //pindah ke node selanjutnya
            } while (temp != NULL); //lakukan looping selama pointer temp belum berisi NULL
            cout << endl;
        }
        else //jika stack kosong
        {
            cout << "STACK KOSONG!!!" << endl; //cetak "STACK KOSONG"
        }
    }
};

int main() //fungsi main
{
    stack s1,s2; //deklarasi dua buah stack
    s1.push(12); //masukkan nilai 12 ke dalam stack s1
    s1.push(13); //masukkan nilai 13 ke dalam stack s1
    s1.push(14); //masukkan nilai 14 ke dalam stack s1
    s1.print(); //cetak isi stack s1

    s2.push(1); //masukkan nilai 1 ke dalam stack s2
    s2.push(2); //masukkan nilai 2 ke dalam stack s2
    s2.push(3); //masukkan nilai 3 ke dalam stack s2
    s2.print(); //cetak isi stack s2

    return 0;
}