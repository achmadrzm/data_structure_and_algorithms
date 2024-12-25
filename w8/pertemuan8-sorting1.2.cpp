//Shell Sort
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
    *a = *b;  // menyalin nilai dari variabel yang ditunjuk oleh pointer b ke dalam variabel yang ditunjuk oleh pointer a
    *b = temp; // menyalin nilai dari variabel temp ke dalam variabel yang ditunjuk oleh pointer b, sehingga nilai dua variabel ditukar
}

// Prosedur pengurutan metode Shell
void ShellSort() { // fungsi untuk mengurutukan data menggunakan teknik shell sort
    int jarak, i, j; //deklarasi variabel bertipe int
    bool sudah; //deklarasi variabel bertipe bool
    jarak = MAX; // variabel jarak bernilai MAX
    while (jarak > 1) { // melakukan pengurutan dengan jarak yang semakin berkurang hingga jarak = 1
        jarak = jarak / 2; // mengurangi jarak menjadi setengah dari nilai sebelumnya
        sudah = false; // menandakan apakah ada pertukaran data atau tidak
        while (!sudah) {
            sudah = true; // diasumsikan tidak ada pertukaran data
            for (j = 0; j < MAX - jarak; j++) { // melakukan pengurutan subset dengan jarak tertentu
                i = j + jarak; // mengambil elemen pada subset yang berjarak jarak
                if (Data[j] > Data[i]) { // jika elemen pada posisi j lebih besar dari elemen pada posisi i, maka dilakukan pertukaran
                    tukar(&Data[j], &Data[i]); // menukar posisi elemen
                    sudah = false; // terjadi pertukaran
                }
            }
        }
    }
}

int main() { //fungsi int main
    srand(0); // inisialisasi seed untuk random number generator

    // Membangkitkan bilangan acak
    cout << "DATA SEBELUM TERURUT" << endl; // menampilkan output
    for (int i = 0; i < MAX; i++) { // loop untuk mengisi array Data dengan bilangan acak
        Data[i] = rand() / 1000 + 1; // menghasilkan bilangan acak dan menyimpannya di array Data
        cout << "Data ke " << i << " : " << Data[i] << endl; // menampilkan data sebelum diurutkan
    }

    ShellSort(); // memanggil prosedur ShellSort() untuk mengurutkan data dalam array

    // Data setelah terurut
    cout << "\nDATA SETELAH TERURUT" << endl; // menampilkan output
    for (int i = 0; i < MAX; i++) { // loop untuk menampilkan nilai setiap elemen Data setelah diurutkan
        cout << "Data ke " << i << " : " << Data[i] << endl; // menampilkan data setelah diurutkan
    }

    return 0;
}