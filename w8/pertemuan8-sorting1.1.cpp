//Bubble Sort
#include <iostream> // library untuk input dan output
#include <stdio.h> // library standar untuk fungsi I/O
#include <stdlib.h> // library standar untuk fungsi umum, termasuk random
#define MAX 10 // definisi konstanta MAX dengan nilai 10

using namespace std; // menggunakan namespace std

int Data[MAX]; // deklarasi array Data dengan ukuran MAX

// Prosedur menukar data
void tukar(int *a, int *b) { // fungsi untuk menukar nilai dua variabel dengan menggunakan pointer
    int temp; // deklarasi variabel int dengan nama temp sebagai tempat penyimpanan sementara
    temp = *a; // menyimpan nilai dari variabel yang ditunjuk oleh pointer a ke dalam variabel temp
    *a = *b; // menyalin nilai dari variabel yang ditunjuk oleh pointer b ke dalam variabel yang ditunjuk oleh pointer a
    *b = temp; // menyalin nilai dari variabel temp ke dalam variabel yang ditunjuk oleh pointer b, sehingga nilai dua variabel ditukar
}

// Prosedur pengurutan metode gelembung
void BubbleSort() { // fungsi untuk mengurutukan data menggunakan teknik bubble sort
    for (int i = 1; i < MAX - 1; i++) { // loop untuk iterasi dalam Bubble Sort
        for (int j = MAX - 1; j >= i; j--) { // loop untuk membandingkan dan menukar elemen
            if (Data[j - 1] > Data[j]) { // jika elemen sebelumnya lebih besar, lakukan pertukaran
                tukar(&Data[j - 1], &Data[j]); // jika elemen sebelumnya lebih besar, lakukan pertukaran
            }
        }
    }
}

int main() { // fungsi int main
    srand(0); // inisialisasi seed untuk random number generator

    // Membangkitkan bilangan acak
    cout << "DATA SEBELUM TERURUT\n"; // menampilkan output
    for (int i = 0; i < MAX; i++) { // loop untuk mengisi array Data dengan bilangan acak
        Data[i] = rand() / 1000 + 1; // menghasilkan bilangan acak dan menyimpannya di array Data
        cout << "Data ke " << i << " : " << Data[i] << endl; // menampilkan data sebelum diurutkan
    }
    
    BubbleSort(); // panggil fungsi BubbleSort untuk mengurutkan array Data

    // Data setelah terurut
    cout << "\nDATA SETELAH TERURUT\n"; // menampilkan output
    for (int i = 0; i < MAX; i++) { // loop untuk menampilkan nilai setiap elemen Data setelah diurutkan
        cout << "Data ke " << i << " : " << Data[i] << endl; // menampilkan data setelah diurutkan
    }

    return 0;
}