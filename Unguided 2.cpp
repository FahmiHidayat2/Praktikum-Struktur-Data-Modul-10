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

