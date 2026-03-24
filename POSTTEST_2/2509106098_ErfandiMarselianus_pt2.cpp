#include <iostream>
#include <iomanip>
#include <string>
#include <cmath>
using namespace std;

struct Kereta {
    int nomorKereta;
    string namaKereta;
    string asal;
    string tujuan;
    int hargaTiket;
    string waktuKeberangkatan;
};

void tampilkanHeader() {
    cout << "\n==========================================================================================================" << endl;
    cout << "| No Kereta | Nama Kereta          | Asal           | Tujuan         | Harga Tiket | Waktu Keberangkatan |" << endl;
    cout << "==========================================================================================================" << endl;
}

void tampilkanSemuaKereta(Kereta *dataKereta, int jumlahKereta) {
    if (jumlahKereta == 0) {
        cout << "\n[!] Belum ada data kereta yang tersedia!" << endl;
        return;
    }
    
    cout << "\n=============================================" << endl;
    cout << "      JADWAL KEBERANGKATAN KERETA API" << endl;
    cout << "=============================================" << endl;
    
    tampilkanHeader();
    
    Kereta *ptr = dataKereta;
    
    while (ptr < dataKereta + jumlahKereta) {
        cout << "| " << setw(8) << ptr->nomorKereta << " | "
             << setw(20) << left << ptr->namaKereta << " | "
             << setw(14) << left << ptr->asal << " | "
             << setw(14) << left << ptr->tujuan << " | "
             << setw(10) << left << ptr->hargaTiket << " | "
             << setw(20) << left << ptr->waktuKeberangkatan << " |" << endl;
        
        ptr++; 
    }
    cout << "==========================================================================================================" << endl;
}

void swapKereta(Kereta *a, Kereta *b) {
    Kereta temp = *a;
    *a = *b;
    *b = temp;
}

void tambahDataKereta(Kereta *&dataKereta, int &jumlahKereta, int &kapasitas) {
    if (jumlahKereta >= kapasitas) {
        kapasitas += 10;
        Kereta *temp = new Kereta[kapasitas];
        
        for (int i = 0; i < jumlahKereta; i++) {
            *(temp + i) = *(dataKereta + i);
        }
        
        delete[] dataKereta;
        dataKereta = temp;
    }
    
    cout << "\n=========================================" << endl;
    cout << "        TAMBAH DATA KERETA BARU" << endl;
    cout << "=========================================" << endl;
    
    Kereta *ptrBaru = &dataKereta[jumlahKereta];
    
    cout << "Masukkan Nomor Kereta        : ";
    cin >> ptrBaru->nomorKereta;
    cin.ignore();
    
    cout << "Masukkan Nama Kereta         : ";
    getline(cin, ptrBaru->namaKereta);
    
    cout << "Masukkan Stasiun Asal        : ";
    getline(cin, ptrBaru->asal);
    
    cout << "Masukkan Stasiun Tujuan      : ";
    getline(cin, ptrBaru->tujuan);
    
    cout << "Masukkan Harga Tiket (Rp)    : ";
    cin >> ptrBaru->hargaTiket;
    cin.ignore();
    
    cout << "Masukkan Waktu Keberangkatan : ";
    getline(cin, ptrBaru->waktuKeberangkatan);
    
    jumlahKereta++;
    
    cout << "\nData kereta berhasil ditambahkan!" << endl;
}

void linearSearchRute(Kereta *dataKereta, int jumlahKereta, string asal, string tujuan) {
    if (jumlahKereta == 0) {
        cout << "\nBelum ada data kereta!" << endl;
        return;
    }
    
    bool ditemukan = false;
    int indeksDitemukan[100];
    int jumlahDitemukan = 0;
    
    for (int i = 0; i < jumlahKereta; i++) {
        if ((dataKereta + i)->asal == asal && (dataKereta + i)->tujuan == tujuan) {
            indeksDitemukan[jumlahDitemukan] = i;
            jumlahDitemukan++;
            ditemukan = true;
        }
    }
    
    if (ditemukan) {
        cout << "\nDitemukan " << jumlahDitemukan << " kereta dengan rute " << asal << " - " << tujuan << ":" << endl;
        tampilkanHeader();
        for (int i = 0; i < jumlahDitemukan; i++) {
            Kereta *ptr = dataKereta + indeksDitemukan[i];
            cout << "| " << setw(8) << ptr->nomorKereta << " | "
                 << setw(20) << left << ptr->namaKereta << " | "
                 << setw(14) << left << ptr->asal << " | "
                 << setw(14) << left << ptr->tujuan << " | "
                 << setw(10) << left << ptr->hargaTiket << " | "
                 << setw(20) << left << ptr->waktuKeberangkatan << " |" << endl;
        }
        cout << "==========================================================================================================" << endl;
    } else {
        cout << "\nTidak ditemukan kereta dengan rute " << asal << " - " << tujuan << endl;
    }
}


int jumpSearchNomor(Kereta *dataKereta, int n, int cariNomor) {
    int step = sqrt(n);
    int prev = 0;
    
    while (prev < n && (dataKereta + min(step, n) - 1)->nomorKereta < cariNomor) {
        prev = step;
        step += sqrt(n);
        if (prev >= n) return -1;
    }
    
    int batas = min(step, n);
    for (int i = prev; i < batas; i++) {
        if ((dataKereta + i)->nomorKereta == cariNomor) {
            return i; 
        }
    }
    
    return -1;
}

void urutkanBerdasarkanNomor(Kereta *dataKereta, int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if ((dataKereta + j)->nomorKereta > (dataKereta + j + 1)->nomorKereta) {
                swapKereta(dataKereta + j, dataKereta + j + 1);
            }
        }
    }
}

void merge(Kereta *arr, int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;
    
    Kereta *L = new Kereta[n1];
    Kereta *R = new Kereta[n2];
    
    for (int i = 0; i < n1; i++)
        *(L + i) = *(arr + left + i);
    for (int j = 0; j < n2; j++)
        *(R + j) = *(arr + mid + 1 + j);
    
    int i = 0, j = 0, k = left;
    
    while (i < n1 && j < n2) {
        if ((L + i)->namaKereta <= (R + j)->namaKereta) {
            *(arr + k) = *(L + i);
            i++;
        } else {
            *(arr + k) = *(R + j);
            j++;
        }
        k++;
    }
    
    while (i < n1) {
        *(arr + k) = *(L + i);
        i++;
        k++;
    }
    
    while (j < n2) {
        *(arr + k) = *(R + j);
        j++;
        k++;
    }
    
    delete[] L;
    delete[] R;
}

void mergeSort(Kereta *arr, int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;
        
        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);
        
        merge(arr, left, mid, right);
    }
}

void urutkanNamaKereta(Kereta *dataKereta, int jumlahKereta) {
    if (jumlahKereta == 0) {
        cout << "\nBelum ada data kereta!" << endl;
        return;
    }
    
    mergeSort(dataKereta, 0, jumlahKereta - 1);
    cout << "\nData berhasil diurutkan berdasarkan Nama Kereta (A-Z) " << endl;
    tampilkanSemuaKereta(dataKereta, jumlahKereta);
}

void selectionSortHarga(Kereta *dataKereta, int n) {
    for (int i = 0; i < n - 1; i++) {
        int minIndex = i;
        
        for (int j = i + 1; j < n; j++) {
            if ((dataKereta + j)->hargaTiket < (dataKereta + minIndex)->hargaTiket) {
                minIndex = j;
            }
        }
        
        if (minIndex != i) {
            swapKereta(dataKereta + i, dataKereta + minIndex);
        }
    }
    
    cout << "\nData berhasil diurutkan berdasarkan Harga Tiket (Termurah ke Termahal)" << endl;
    tampilkanSemuaKereta(dataKereta, n);
}

void tampilkanMenu() {
    cout << "\n=========================================" << endl;
    cout << "   SISTEM INFORMASI MANAJEMEN KERETA API" << endl;
    cout << "=========================================" << endl;
    cout << "1. Tampilkan Jadwal Semua Kereta" << endl;
    cout << "2. Tambah Data Kereta Baru" << endl;
    cout << "3. Cari Kereta Berdasarkan Rute " << endl;
    cout << "4. Cari Kereta Berdasarkan Nomor" << endl;
    cout << "5. Urutkan Berdasarkan Nama Kereta" << endl;
    cout << "6. Urutkan Berdasarkan Harga Tiket" << endl;
    cout << "7. Keluar" << endl;
    cout << "-----------------------------------------" << endl;
    cout << "Pilihan Anda : ";
}

int main() {
    int kapasitas = 20;
    Kereta *dataKereta = new Kereta[kapasitas];
    int jumlahKereta = 0;
    int pilihan;
    
    Kereta *ptr1 = &dataKereta[0];
    ptr1->nomorKereta = 103;
    ptr1->namaKereta = "Argo Bromo";
    ptr1->asal = "Jakarta";
    ptr1->tujuan = "Surabaya";
    ptr1->hargaTiket = 350000;
    ptr1->waktuKeberangkatan = "08:00";
    jumlahKereta++;
    
    Kereta *ptr2 = &dataKereta[1];
    ptr2->nomorKereta = 101;
    ptr2->namaKereta = "Sancaka";
    ptr2->asal = "Yogyakarta";
    ptr2->tujuan = "Surabaya";
    ptr2->hargaTiket = 150000;
    ptr2->waktuKeberangkatan = "10:30";
    jumlahKereta++;
    
    Kereta *ptr3 = &dataKereta[2];
    ptr3->nomorKereta = 105;
    ptr3->namaKereta = "Bima";
    ptr3->asal = "Jakarta";
    ptr3->tujuan = "Bandung";
    ptr3->hargaTiket = 120000;
    ptr3->waktuKeberangkatan = "07:15";
    jumlahKereta++;
    
    Kereta *ptr4 = &dataKereta[3];
    ptr4->nomorKereta = 102;
    ptr4->namaKereta = "Gajayana";
    ptr4->asal = "Malang";
    ptr4->tujuan = "Jakarta";
    ptr4->hargaTiket = 400000;
    ptr4->waktuKeberangkatan = "13:45";
    jumlahKereta++;
    
    Kereta *ptr5 = &dataKereta[4];
    ptr5->nomorKereta = 104;
    ptr5->namaKereta = "Bangunkarta";
    ptr5->asal = "Surabaya";
    ptr5->tujuan = "Jakarta";
    ptr5->hargaTiket = 380000;
    ptr5->waktuKeberangkatan = "09:00";
    jumlahKereta++;
    
    do {
        tampilkanMenu();
        cin >> pilihan;
        
        switch(pilihan) {
            case 1:
                tampilkanSemuaKereta(dataKereta, jumlahKereta);
                break;
                
            case 2:
                tambahDataKereta(dataKereta, jumlahKereta, kapasitas);
                break;
                
            case 3: {
                if (jumlahKereta == 0) {
                    cout << "\nBelum ada data kereta!" << endl;
                    break;
                }
                
                string asal, tujuan;
                cin.ignore();
                cout << "\n=== BERDASARKAN RUTE ===" << endl;
                cout << "Masukkan Stasiun Asal   : ";
                getline(cin, asal);
                cout << "Masukkan Stasiun Tujuan : ";
                getline(cin, tujuan);
                
                linearSearchRute(dataKereta, jumlahKereta, asal, tujuan);
                break;
            }
            
            case 4: {
                if (jumlahKereta == 0) {
                    cout << "\nBelum ada data kereta!" << endl;
                    break;
                }
                
                Kereta *dataTerurut = new Kereta[jumlahKereta];
                for (int i = 0; i < jumlahKereta; i++) {
                    *(dataTerurut + i) = *(dataKereta + i);
                }
                
                urutkanBerdasarkanNomor(dataTerurut, jumlahKereta);
                
                int cariNomor;
                cout << "\n=== BERDASARKAN NOMOR KERETA ===" << endl;
                cout << "Masukkan Nomor Kereta yang dicari: ";
                cin >> cariNomor;
                
                int indeks = jumpSearchNomor(dataTerurut, jumlahKereta, cariNomor);
                
                if (indeks != -1) {
                    cout << "\nKereta ditemukan!" << endl;
                    tampilkanHeader();
                    Kereta *ptr = dataTerurut + indeks;
                    cout << "| " << setw(8) << ptr->nomorKereta << " | "
                         << setw(20) << left << ptr->namaKereta << " | "
                         << setw(14) << left << ptr->asal << " | "
                         << setw(14) << left << ptr->tujuan << " | "
                         << setw(10) << left << ptr->hargaTiket << " | "
                         << setw(20) << left << ptr->waktuKeberangkatan << " |" << endl;
                    cout << "==========================================================================================================" << endl;
                } else {
                    cout << "\nTidak ditemukan kereta dengan nomor " << cariNomor << endl;
                }
                
                delete[] dataTerurut;
                break;
            }
            
            case 5:
                urutkanNamaKereta(dataKereta, jumlahKereta);
                break;
                
            case 6:
                selectionSortHarga(dataKereta, jumlahKereta);
                break;
                
            case 7:
                cout << "\n=========================================" << endl;
                cout << "   Terima kasih telah menggunakan program" << endl;
                cout << "=========================================" << endl;
                delete[] dataKereta;
                break;
                
            default:
                cout << "\nPilihan tidak valid! Silakan coba lagi." << endl;
        }
    } while (pilihan != 7);
    
    return 0;
}