#include <iostream>
using namespace std;


void reverseArray(int* arr, int n) {
    int* start = arr;          
    int* end = arr + (n - 1);   

    while (start < end) {
        int temp = *start;
        *start = *end;
        *end = temp;
        
        start++;
        end--;
    }
}


void tampilkanArray(int* arr, int n, string keterangan) {
    cout << "\n" << keterangan << ":\n";
    cout << "----------------------------------------\n";
    
    int* p = arr; 
    
    for (int i = 0; i < n; i++) {
        cout << "Elemen [" << i << "]: " << *p 
             << "\t Alamat: " << p << endl;
        p++; 
    }

}

int main() {
    int bilanganPrima[7] = {2, 3, 5, 7, 11, 13, 17};
    int ukuran = sizeof(bilanganPrima) / sizeof(bilanganPrima[0]);
    
    cout << "MEMBALIK ARRAY MENGGUNAKAN POINTER\n";

    

    cout << "ARRAY SEBELUM DIBALIK:";
    tampilkanArray(bilanganPrima, ukuran, "");
    
    cout << "\nProses pembalikan array...\n";
    reverseArray(bilanganPrima, ukuran);
    
    cout << "ARRAY SETELAH DIBALIK:";
    tampilkanArray(bilanganPrima, ukuran, "");
    

    cout << "\nVerifikasi HASIL:\n";
    cout << "Urutan asli    : 2, 3, 5, 7, 11, 13, 17\n";
    cout << "Urutan terbalik: ";
    
    int* tampil = bilanganPrima;
    for (int i = 0; i < ukuran; i++) {
        cout << *tampil;
        if (i < ukuran - 1) cout << ", ";
        tampil++;
    }
    
 
    cout << "\nAKSES MENGGUNAKAN POINTER:\n";
   
    
    int* ptr = bilanganPrima; 
    cout << "Alamat elemen pertama (ptr)      : " << ptr << endl;
    cout << "Nilai elemen pertama (*ptr)      : " << *ptr << endl;
    cout << "Alamat elemen kedua (ptr + 1)    : " << ptr + 1 << endl;
    cout << "Nilai elemen kedua (*(ptr + 1))  : " << *(ptr + 1) << endl;
  
    
    return 0;
}