//Binary Insert Sort
#include <iostream> // library untuk input dan output
#include <cstdlib> // library standar untuk fungsi umum, termasuk random
#define MAX 10 // definisi konstanta MAX dengan nilai 10

using namespace std; // menggunakan namespace std

int Data[MAX]; // deklarasi array Data dengan ukuran MAX

// Fungsi pengurutan penyisipan biner
void binaryInsertSort() { // fungsi untuk mengurutukan data menggunakan teknik binary insert sort
    int i, j, l, r, m, x; // deklarasi variabel bertipe int
    for (i = 1; i < MAX; i++) { // loop untuk iterasi dalam binary insert Sort
        x = Data[i]; // simpan elemen saat ini untuk disisipkan
        l = 0; // menentukan batas bawah pencarian
        r = i - 1; // menentukan batas atas pencarian
        while (l <= r) { // melakukan perulangan jika batas bawah lebih kecil sama dengan batas atas
            m = (l + r) / 2; // menentukan data tengah sebagai titik perbandingan
            if (x < Data[m]) // jika elemen saat ini lebih kecil dari elemen di tengah
                r = m - 1; // maka perbarui batas atas pencarian
            else // jika tidak
                l = m + 1; // maka perbarui batas bawah pencarian
        }
        for (j = i - 1; j >= l; j--) { // melakukan perulangan
            Data[j + 1] = Data[j]; // geser elemen ke kanan untuk memberikan tempat pada posisi sisipan
        }
        Data[l] = x; // sisipkan elemen saat ini pada posisi yang sesuai
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
    binaryInsertSort(); // panggil fungsi binary insert sort untuk mengurutkan array Data

    // Data setelah terurut
    cout << "\nDATA SETELAH TERURUT" << endl; // menampilkan output
    for (i = 0; i < MAX; i++) { // loop untuk menampilkan nilai setiap elemen Data setelah diurutkan
        cout << "Data ke " << i << " : " << Data[i] << endl; // menampilkan data setelah diurutkan
    }

    return 0;
}