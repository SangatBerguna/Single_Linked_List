#include <iostream>
using namespace std;

// Deklarasi single linked list untuk Daftar Tugas
struct Tugas {
    string namaTugas;
    int nomorTugas;
    string deadlineTugas;
    Tugas* next;
};

Tugas *kepala, *ekor, *saat_ini, *node_baru, *hapus, *sebelum;

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

// Menambahkan node di tengah single linked list
void addMiddle(string nama, int nomor, string deadline, int posisi) {
    if (posisi < 1 || posisi > countSingleLinkedList()) {
        cout << "Posisi diluar jangkauan" << endl;
    } else if (posisi == 1) {
        cout << "Posisi bukan posisi tengah" << endl;
    } else {
        node_baru = new Tugas();
        node_baru->namaTugas = nama;
        node_baru->nomorTugas = nomor;
        node_baru->deadlineTugas = deadline;
        saat_ini = kepala;
        int nomor = 1;
        while (nomor < posisi - 1) {
            saat_ini = saat_ini->next;
            nomor++;
        }
        node_baru->next = saat_ini->next;
        saat_ini->next = node_baru;
    }
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

// Menghapus node di tengah single linked list
void removeMiddle(int posisi) {
    if (posisi < 1 || posisi > countSingleLinkedList()) {
        cout << "Posisi diluar jangkauan" << endl;
    } else if (posisi == 1) {
        cout << "Posisi bukan posisi tengah" << endl;
    } else {
        int nomor = 1;
        saat_ini = kepala;
        while (nomor <= posisi) {
            if (nomor == posisi-1) {
                sebelum = saat_ini;
            }
            if (nomor == posisi) {
                hapus = saat_ini;
            }
            saat_ini = saat_ini->next;
            nomor++;
        }
        sebelum->next = saat_ini;
        delete hapus;
    }
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

// Mengubah node di tengah single linked list
void changeMiddle(string nama, int nomor, string deadline, int posisi) {
    if (posisi < 1 || posisi > countSingleLinkedList()) {
        cout << "Posisi diluar jangkauan" << endl;
    } else if (posisi == 1 || posisi == countSingleLinkedList()) {
        cout << "Posisi bukan posisi tengah" << endl;
    } else {
        saat_ini = kepala;
        int nomor = 1;
        while (nomor < posisi) {
            saat_ini = saat_ini->next;
            nomor++;
        }
        saat_ini->namaTugas = nama;
        saat_ini->nomorTugas = nomor;
        saat_ini->deadlineTugas = deadline;
    }
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

    addMiddle("Tugas 6", 6, "2024-05-28", 2);

    printSingleLinkedList();
  
    cout << "\n\n" << endl;

    addMiddle("Tugas 7", 7, "2024-05-29", 2);

    printSingleLinkedList();
  
    cout << "\n\n" << endl;
}
