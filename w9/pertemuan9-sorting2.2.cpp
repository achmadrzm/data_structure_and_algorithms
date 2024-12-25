//Straight Insert Sort
#include <iostream> // library untuk input dan output
#include <cstdlib> // library standar untuk fungsi umum, termasuk random
#define MAX 10 // definisi konstanta MAX dengan nilai 10

using namespace std; // menggunakan namespace std

int Data[MAX]; // deklarasi array Data dengan ukuran MAX

// Fungsi pengurutan penyisipan langsung
void StraightInsertSort() { // fungsi untuk mengurutukan data menggunakan teknik straight insert sort
    int i, j, x; // deklarasi variabel bertipe int
    for (i = 1; i < MAX; i++) { // loop untuk iterasi dalam straigh insert Sort
        x = Data[i]; // menyimpan nilai Data[i] ke dalam variabel x
        j = i - 1; // inisialisasi variabel j dengan i - 1
        while (j >= 0 && x < Data[j]) { // loop untuk memindahkan elemen-elemen yang lebih besar dari x ke posisi berikutnya
            Data[j + 1] = Data[j]; // memindahkan elemen ke posisi berikutnya
            j--; // decrement  nilai j
        }
        Data[j + 1] = x; // menyisipkan nilai x ke posisi yang sesuai
    }
}

int main() { // fungsi int main
    int i; // deklrasi variabel bertipe int
    srand(0); // inisialisasi seed untuk random number generator

    // Membangkitkan bilangan acak
    cout << "DATA SEBELUM TERURUT" << endl; // menampilkan output
    for (i = 0; i < MAX; i++) { // loop untuk mengisi array Data dengan bilangan acak
        Data[i] = rand() / 1000 + 1; // menghasilkan bilangan acak dan menyimpannya di array Data
        cout << "Data ke " << i << " : " << Data[i] << endl; // menampilkan data sebelum diurutkan
    }
    StraightInsertSort(); // panggil fungsi straight insert sort untuk mengurutkan array Data

    // Data setelah terurut
    cout << "\nDATA SETELAH TERURUT" << endl; // menampilkan output
    for (i = 0; i < MAX; i++) { // loop untuk menampilkan nilai setiap elemen Data setelah diurutkan
        cout << "Data ke " << i << " : " << Data[i] << endl; // menampilkan data setelah diurutkan
    }

    return 0;
}