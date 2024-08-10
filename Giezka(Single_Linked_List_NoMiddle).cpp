#include <iostream>
using namespace std;

// Deklarasi single linked list untuk Daftar Tugas
struct Tugas {
    string namaTugas;
    int nomorTugas;
    string deadlineTugas;
    Tugas* next;
};

Tugas *kepala, *ekor, *saat_ini, *node_baru, *hapus;

// Membuat single linked list
void createSingleLinkedList(string nama, int nomor, string deadline) {
    kepala = new Tugas();
    kepala->namaTugas = nama;
    kepala->nomorTugas = nomor;
    kepala->deadlineTugas = deadline;
    kepala->next = NULL;
    ekor = kepala;
}

// Menghitung jumlah node di single linked list
int countSingleLinkedList() {
    saat_ini = kepala;
    int jumlah = 0;
    while (saat_ini != NULL) {
        jumlah++;
        saat_ini = saat_ini->next;
    }
    return jumlah;
}

// Menambahkan node di awal single linked list
void addFirst(string nama, int nomor, string deadline) {
    node_baru = new Tugas();
    node_baru->namaTugas = nama;
    node_baru->nomorTugas = nomor;
    node_baru->deadlineTugas = deadline;
    node_baru->next = kepala;
    kepala = node_baru;
}

// Menambahkan node di akhir single linked list
void addLast(string nama, int nomor, string deadline) {
    node_baru = new Tugas();
    node_baru->namaTugas = nama;
    node_baru->nomorTugas = nomor;
    node_baru->deadlineTugas = deadline;
    node_baru->next = NULL;
    ekor->next = node_baru;
    ekor = node_baru;
}

// Menghapus node di awal single linked list
void removeFirst() {
    hapus = kepala;
    kepala = kepala->next;
    delete hapus;
}

// Menghapus node di akhir single linked list
void removeLast() {
    hapus = ekor;
    saat_ini = kepala;
    while (saat_ini->next != ekor) {
        saat_ini = saat_ini->next;
    }
    ekor = saat_ini;
    ekor->next = NULL;
    delete hapus;
}

// Mengubah node di awal single linked list
void changeFirst(string nama, int nomor, string deadline) {
    kepala->namaTugas = nama;
    kepala->nomorTugas = nomor;
    kepala->deadlineTugas = deadline;
}

// Mengubah node di akhir single linked list
void changeLast(string nama, int nomor, string deadline) {
    ekor->namaTugas = nama;
    ekor->nomorTugas = nomor;
    ekor->deadlineTugas = deadline;
}

// Menampilkan semua tugas dalam single linked list
void printSingleLinkedList() {
    cout << "Jumlah tugas ada : " << countSingleLinkedList() << endl;
    saat_ini = kepala;
    while (saat_ini != NULL) {
        cout << "Nama Tugas : " << saat_ini->namaTugas << endl;
        cout << "Nomor Tugas : " << saat_ini->nomorTugas << endl;
        cout << "Deadline Tugas : " << saat_ini->deadlineTugas << endl;
        saat_ini = saat_ini->next;
    }
}

int main() {
    createSingleLinkedList("Tugas 1", 1, "2024-05-23");

    printSingleLinkedList();

    cout << "\n\n" << endl;

    addFirst("Tugas 2", 2, "2024-05-24");

    printSingleLinkedList();
  
    cout << "\n\n" << endl;

    addLast("Tugas 3", 3, "2024-05-25");

    printSingleLinkedList();
  
    cout << "\n\n" << endl;

    removeFirst();

    printSingleLinkedList();
  
    cout << "\n\n" << endl;

    addLast("Tugas 4", 4, "2024-05-26");

    printSingleLinkedList();
  
    cout << "\n\n" << endl;

    removeLast();

    printSingleLinkedList();
  
    cout << "\n\n" << endl;

    changeFirst("Tugas 5", 5, "2024-05-27");

    printSingleLinkedList();
  
    cout << "\n\n" << endl;
}
