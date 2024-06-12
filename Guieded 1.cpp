#include<iostream> // Mengimpor library iostream untuk input-output
#include<iomanip> // Mengimpor library iomanip untuk format output
using namespace std; // Menggunakan namespace std untuk memudahkan penggunaan fungsi dari library

string simpul[7] = {"ciamis", "Bandung","Bekasi","Tasikmalaya","cianjur","Purwokerto", "Yogyakarta"}; // Array simpul yang berisi nama-nama kota

int busur [7][7] = { // Matriks busur yang merepresentasikan jarak antar kota
    {0, 7, 8, 0, 0, 0, 0},
    {0, 0, 5, 0, 9, 15, 0},
    {0, 5, 0, 9, 5, 0, 0},
    {0, 0, 0, 2, 4, 0, 8},
    {3, 0, 0, 1, 0, 0, 0},
    {0, 0, 7, 0, 0, 9, 4},
    {0, 0, 0, 0, 8, 0, 0}
};

void tampilGraph(){ // Fungsi untuk menampilkan graf
    for(int i = 0; i < 7; i++){ // Iterasi untuk setiap simpul
        cout<<simpul[i]<<" : "<<endl; // Menampilkan nama kota
        for(int j = 0; j < 7; j++){ // Iterasi untuk setiap busur
            if(busur[i][j] != 0 ) // Jika terdapat jarak antar kota
            cout<<"-->"<<simpul[j]<<" ("<<busur[i][j]<<")"<<endl; // Menampilkan koneksi antar kota beserta jaraknya
        }
        cout<<endl; // Baris kosong untuk pemisah
    }
}

int main(){ // Fungsi utama
    tampilGraph(); // Memanggil fungsi tampilGraph untuk menampilkan graf
    return 0; // Mengembalikan nilai 0 sebagai penanda program berjalan dengan sukses
}
