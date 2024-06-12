# <h1 align="center">Laporan Praktikum Modul Graph dan Tree</h1>
<p align="center">Fahmi Hidayat</p>

## Dasar Teori
### Graph
Graph adalah struktur data yang terdiri dari simpul-simpul yang terhubung oleh sisi atau edge. Graph dapat digunakan untuk merepresentasikan berbagai konsep, seperti jaringan sosial, rute perjalanan, atau jaringan komputer. Dalam pemrograman, Graph sering digunakan untuk menyelesaikan berbagai masalah, seperti mencari jalur terpendek, pemetaan jaringan, dan banyak lagi. Implementasi Graph dalam C++ dapat dilakukan dengan berbagai cara, salah satunya adalah dengan menggunakan representasi adjacency list.Graf adalah salah satu materi dalam matematika diskrit, graf digunakan untuk memberikan visualisasi atau gambaran antar objek yang disimbolkan dengan titik dan dihubungkan dengan garis [1] Dalam adjacency list, setiap simpul dalam Graph memiliki daftar simpul terhubung langsung dengan simpul tersebut. Struktur data ini dapat diimplementasikan menggunakan array 2D, di mana setiap baris mewakili simpul dan setiap elemen dalam baris adalah simpul yang terhubung dengan simpul tersebut.
### Tree
Tree adalah struktur data hierarkis yang terdiri dari simpul-simpul yang terhubung dalam pola hirarkis, mirip dengan struktur pohon kebalikan. Pada pohon, simpul paling atas disebut simpul root, dan setiap simpul memiliki anak-anak yang terhubung ke bawahnya. Tree sangat penting dalam pemrograman dan komputer sains karena berbagai algoritma dan struktur data didasarkan pada konsep pohon. Salah satu jenis pohon yang umum adalah pohon biner, di mana setiap simpul memiliki maksimal dua anak, yaitu anak kiri dan anak kanan. Implementasi pohon biner dalam C++ dapat dilakukan dengan menggunakan kelas dan pointer. Setiap simpul dalam pohon direpresentasikan sebagai objek dengan atribut yang menyimpan nilai simpul dan pointer ke anak kiri dan kanan.

Dengan pemahaman tentang Graph dan Tree dalam konteks implementasi C++, Anda dapat menggunakannya untuk menyelesaikan berbagai masalah pemrograman dan membangun aplikasi yang kompleks. Implementasi yang tepat akan tergantung pada kebutuhan dan karakteristik masalah yang sedang Anda hadapi.

## Guided 

### 1. Guided 1

```C++
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
```
### 2 Guided 2
```c++
#include<iostream>
#include<iomanip> // Menambahkan library iomanip untuk format output
using namespace std;

struct pohon {
    pohon * kanan;
    char data;
    pohon * kiri;
};

//Deklarasi variabel global
pohon * simpul;
pohon * root;
pohon * saatIni;
pohon * helperA;
pohon * helperB;
pohon * alamat[256];

// Fungsi Inisiasi
void inisialisasi(){
    root = NULL;
    saatIni = NULL;
    helperA = NULL;
    helperB = NULL;
}

// Fungsi membuat simpul baru
void simpulBaru(char dataMasukkan){
    simpul = new pohon;
    simpul->data = dataMasukkan;
    simpul->kanan = NULL;
    simpul->kiri = NULL;
}

//Fungsi membuat simpul akar
void simpulAkar(){
    if (root == NULL) {
        char dataAnda;
        cout << "Masukkan data akar: ";
        cin >> dataAnda;
        simpulBaru(dataAnda);
        root = simpul;
        cout << "Simpul akar berhasil dibuat...\n";
    } else {
        cout << "Simpul akar sudah ada...\n";
    }
}

//Fungsi menambah simpul
void tambahSimpul() {
    if (root != NULL) {
        int i = 1, j = 1, penanda = 0;
        char dataUser;
        alamat[i] = root;

        while (penanda == 0 && j < 25) {
            cout << "Masukkan data kiri : ";
            cin >> dataUser;
            if (dataUser != '0') {
                simpulBaru(dataUser);
                saatIni = alamat[i];
                saatIni->kiri = simpul;
                j++;
                alamat[j] = simpul;
            } else {
                penanda = 1;
                j++;
                alamat[j] = NULL;
            }
            if (penanda == 0) {
                cout << "Masukkan data kanan : ";
                cin >> dataUser;
                if (dataUser != '0') {
                    simpulBaru(dataUser);
                    saatIni = alamat[i];
                    saatIni->kanan = simpul;
                    j++;
                    alamat[j] = simpul;
                } else {
                    penanda = 1;
                    j++;
                    alamat[j] = NULL;
                }
            }
            i++;
        }
    }
}

//Fungsi membaca pohon
void bacaPohon(){
    if (root != NULL) {
        int i = 1, n = 1, pencacah = 0;
        cout << endl;
        while (alamat[i] != NULL){
            saatIni = alamat[i];
            if (saatIni->data < 10) {
                cout << " " << saatIni->data << " "; // Menambahkan spasi untuk memformat output agar rapi
            } else {
                cout << saatIni->data << " ";
            }
            pencacah++;
            if (pencacah == n){
                cout << endl;
                n = n * 2;
                pencacah = 0;
            }
            i++;
        }
    }
}

int main(){
    inisialisasi();
    simpulAkar();
    tambahSimpul();
    bacaPohon();
    return 0;
}
```

## Unguided 

### 1. Buatlah program graph dengan menggunakan inputan user untuk menghitung jarak dari sebuah kota ke kota lainnya.

```C++
#include <iostream>
#include <iomanip>
#include <vector>
#include <string>
#include <unordered_map>
using namespace std;

vector<string> Fahmi_Hidayat_2311110063;
vector<vector<int>> busur;
unordered_map<string, int> kotaIndex;

void isiFahmi_Hidayat_2311110063(int jumlahSimpul) {
    string namaKota;
    cout << "Masukkan nama-nama kota:" << endl;
    cin.ignore();
    for (int i = 0; i < jumlahSimpul; i++) {
        cout << "Nama kota " << i + 1 << ": ";
        getline(cin, namaKota);
        Fahmi_Hidayat_2311110063.push_back(namaKota);
        kotaIndex[namaKota] = i;
    }
    busur.resize(jumlahSimpul, vector<int>(jumlahSimpul, 0));
}

void isiBusur() {
    int jarak;
    cout << "Masukkan jarak antar kota (0 jika tidak ada jalur langsung):" << endl;
    for (size_t i = 0; i < Fahmi_Hidayat_2311110063.size(); i++) {
        for (size_t j = 0; j < Fahmi_Hidayat_2311110063.size(); j++) {
            if (i != j) {
                cout << "Jarak dari " << Fahmi_Hidayat_2311110063[i] << " ke " << Fahmi_Hidayat_2311110063[j] << ": ";
                cin >> jarak;
                busur[i][j] = jarak;
            }
        }
    }
}

void tampilGraph() {
    cout << left << setw(12) << "Kota Asal" << " | ";
    for (const auto& kota : Fahmi_Hidayat_2311110063) {
        cout << setw(10) << kota << " | ";
    }
    cout << endl;

    for (size_t i = 0; i < Fahmi_Hidayat_2311110063.size(); i++) {
        cout << left << setw(12) << Fahmi_Hidayat_2311110063[i] << " | ";
        for (size_t j = 0; j < Fahmi_Hidayat_2311110063.size(); j++) {
            cout << setw(10) << busur[i][j] << " | ";
        }
        cout << endl;
    }
}

int hitungJarak(const vector<string>& perjalanan) {
    int totalJarak = 0;
    for (size_t i = 0; i < perjalanan.size() - 1; i++) {
        int asal = kotaIndex[perjalanan[i]];
        int tujuan = kotaIndex[perjalanan[i + 1]];
        totalJarak += busur[asal][tujuan];
    }
    return totalJarak;
}

int main() {
    int jumlahSimpul;
    cout << "Masukkan jumlah kota: ";
    cin >> jumlahSimpul;

    isiFahmi_Hidayat_2311110063(jumlahSimpul);
    isiBusur();
    tampilGraph();

    int jumlahPerjalanan;
    cout << "Masukkan jumlah kota dalam perjalanan: ";
    cin >> jumlahPerjalanan;
    vector<string> perjalanan(jumlahPerjalanan);
    cout << "Masukkan nama-nama kota dalam perjalanan:" << endl;
    for (int i = 0; i < jumlahPerjalanan; i++) {
        cout << "Kota " << i + 1 << ": ";
        cin >> perjalanan[i];
    }

    int jarakTotal = hitungJarak(perjalanan);
    cout << "Jarak total perjalanan: ";
    for (const auto& kota : perjalanan) {
        cout << kota << " ";
    }
    cout << "adalah " << jarakTotal << " km" << endl;

    return 0;
}
```
Program ini memungkinkan pengguna untuk memasukkan data jarak antar kota dan menghitung total jarak dari sebuah kota ke kota lainnya. Pengguna diminta untuk memasukkan jumlah kota yang akan dimasukkan ke dalam sistem, kemudian diminta untuk memasukkan nama-nama kota tersebut. Setelah itu, program meminta pengguna untuk memasukkan jarak antar kota dengan memasukkan jarak dari setiap pasangan kota. Program akan menampilkan matriks jarak antar kota berdasarkan input pengguna. Selanjutnya, pengguna diminta untuk memilih kota awal dan kota tujuan. Program akan menghitung total jarak dari kota awal ke kota tujuan berdasarkan matriks jarak yang telah dimasukkan, dan menampilkannya kepada pengguna. Dalam implementasinya, program menggunakan struktur data vektor untuk menyimpan nama-nama kota dan matriks jarak antar kota, serta unordered_map untuk memetakan nama kota ke indeks dalam vektor kota. Hal ini memungkinkan program untuk mengelola data dengan efisien dan akurat.

### 2. Modifikasi guided tree diatas dengan program menu menggunakan input data tree dari user dan tampilkan pada pre-order, inorder, dan post order!
```c++
#include <iostream>
#include <stack>
#include <vector>
using namespace std;

struct Node {
    int data;
    Node* kiri;
    Node* kanan;
    Node(int nilai) : data(nilai), kiri(nullptr), kanan(nullptr) {}
};

Node* buatPohon() {
    int nilai;
    cout << "Masukkan nilai node (gunakan -1 jika node kosong): ";
    cin >> nilai;
    if (nilai == -1) {
        return nullptr;
    }
    Node* node = new Node(nilai);
    cout << "Masukkan anak kiri dari " << nilai << ":" << endl;
    node->kiri = buatPohon();
    cout << "Masukkan anak kanan dari " << nilai << ":" << endl;
    node->kanan = buatPohon();
    return node;
}

void preOrder(Node* root) {
    if (root == nullptr) {
        return;
    }
    cout << root->data << " ";
    preOrder(root->kiri);
    preOrder(root->kanan);
}

void inOrder(Node* root) {
    if (root == nullptr) {
        return;
    }
    inOrder(root->kiri);
    cout << root->data << " ";
    inOrder(root->kanan);
}

void postOrder(Node* root) {
    if (root == nullptr) {
        return;
    }
    postOrder(root->kiri);
    postOrder(root->kanan);
    cout << root->data << " ";
}

int main() {
    cout << "=== Membuat Tree ===" << endl;
    Node* root = buatPohon();

    cout << endl << "=== Pre-order Traversal ===" << endl;
    preOrder(root);
    cout << endl;

    cout << endl << "=== In-order Traversal ===" << endl;
    inOrder(root);
    cout << endl;

    cout << endl << "=== Post-order Traversal ===" << endl;
    postOrder(root);
    cout << endl;

    return 0;
}
```
Program yang dimodifikasi ini memungkinkan pengguna untuk membuat sebuah pohon biner dan melakukan tiga jenis traversal: pre-order, in-order, dan post-order. Pengguna diminta untuk memasukkan nilai untuk setiap node pohon, dengan nilai -1 menandakan bahwa node tersebut adalah node kosong (leaf). Setelah memasukkan nilai-nilai node, program akan menampilkan hasil dari setiap jenis traversal secara berurutan: pre-order, in-order, dan post-order. Melalui program ini, pengguna dapat dengan mudah memahami cara kerja dari setiap jenis traversal dan mengeksplorasi struktur pohon biner dengan input yang disesuaikan sesuai keinginan.


## Kesimpulan
Dalam praktikum ini, Belajar mengenai konsep dasar Graph dan Tree dalam pemrograman menggunakan C++. Graph merupakan struktur data yang terdiri dari simpul-simpul yang saling terhubung melalui sisi atau edge, sedangkan Tree merupakan struktur hierarkis dengan simpul root dan anak-anaknya yang terkoneksi secara berjenjang. Kami juga mempelajari berbagai teknik untuk menerapkan dan memanipulasi Graph dan Tree, termasuk membuat Graph dari input pengguna, melakukan traversal pada Tree, serta menghitung jarak antara simpul-simpul pada Graph. Praktikum ini memberikan pemahaman yang lebih dalam tentang konsep fundamental Graph dan Tree serta penerapannya dalam pemrograman, yang sangat bermanfaat dalam memecahkan berbagai masalah pemrograman yang kompleks.

## Referensi
[1] I. H. Pratama and A. H. Wijaya, “Teori graf dan implementasinya dalam menentukan rute efektif perjalanan wisata,” pp. 1–10, 2022.
