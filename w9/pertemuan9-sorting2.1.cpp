//Selection Sort
#include <iostream> // library untuk input dan output
#include <cstdlib> // library standar untuk fungsi umum, termasuk random
#define MAX 10 // definisi konstanta MAX dengan nilai 10

using namespace std; // menggunakan namespace std

int Data[MAX]; // deklarasi array Data dengan ukuran MAX

// Fungsi pertukaran bilangan
void tukar(int* a, int* b) { // fungsi untuk menukar nilai dua variabel dengan menggunakan pointer
    int temp; // deklarasi variabel int dengan nama temp sebagai tempat penyimpanan sementara
    temp = *a; // menyimpan nilai dari variabel yang ditunjuk oleh pointer a ke dalam variabel temp
    *a = *b; // menyalin nilai dari variabel yang ditunjuk oleh pointer b ke dalam variabel yang ditunjuk oleh pointer a
    *b = temp; // menyalin nilai dari variabel temp ke dalam variabel yang ditunjuk oleh pointer b, sehingga nilai dua variabel ditukar
}

// Fungsi pengurutan penyisipan biner
void selectionSort() { // fungsi untuk mengurutukan data menggunakan teknik selection sort
    int i, j, k; // deklarasi variabel bertipe int
    for (i = 0; i < MAX - 1; i++) { // loop untuk iterasi dalam selection Sort
        k = i; // inisialisasi indeks elemen terkecil dengan i
        for (j = i + 1; j < MAX; j++) // loop untuk mencari elemen terkecil setelah indeks i
            if (Data[k] > Data[j]) // jika elemen yang sedang dicek lebih besar dari elemen terkecil saat ini
                k = j; // update indeks elemen terkecil menjadi j
        tukar(&Data[i], &Data[k]); // tukar elemen terkecil dengan elemen pada indeks i
    }
}

int main() { // fungsi int main
    srand(0); // inisialisasi seed untuk random number generator

    // Membangkitkan bilangan acak
    cout << "DATA SEBELUM TERURUT" << endl; // menampilkan output
    for (int i = 0; i < MAX; i++) { // loop untuk mengisi array Data dengan bilangan acak
        Data[i] = (rand() % 1000) + 1; // menghasilkan bilangan acak dan menyimpannya di array Data
        cout << "Data ke " << i << " : " << Data[i] << endl; // menampilkan data sebelum diurutkan
    }
    selectionSort(); // panggil fungsi selection sort untuk mengurutkan array Data

    // Data setelah terurut
    cout << "\nDATA SETELAH TERURUT" << endl; // menampilkan output
    for (int i = 0; i < MAX; i++) { // loop untuk menampilkan nilai setiap elemen Data setelah diurutkan
        cout << "Data ke " << i << " : " << Data[i] << endl; // menampilkan data setelah diurutkan
    }

    return 0;
}