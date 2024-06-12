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

