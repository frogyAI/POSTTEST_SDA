#include <iostream>
#include <string>
using namespace std;

struct Mahasiswa {
    string nama;
    string nim;
    float ipk;
};

int main() {
    Mahasiswa mhs[5];
    
 
    cout << "INPUT DATA 5 MAHASISWA\n";
    cout << "======================\n";
    
    for(int i = 0; i < 5; i++) {
        cout << "\nMahasiswa ke-" << i+1 << endl;
        
        cout << "Nama: ";
        cin.ignore();
        getline(cin, mhs[i].nama);
        
        cout << "NIM: ";
        getline(cin, mhs[i].nim);
        
        cout << "IPK: ";
        cin >> mhs[i].ipk;
    }
    

    cout << "\n\nDATA MAHASISWA\n";
    cout << "==============\n";
    for(int i = 0; i < 5; i++) {
        cout << i+1 << ". " << mhs[i].nama << " - " 
             << mhs[i].nim << " - " << mhs[i].ipk << endl;
    }
    
    
    int tertinggi = 0;
    for(int i = 1; i < 5; i++) {
        if(mhs[i].ipk > mhs[tertinggi].ipk) {
            tertinggi = i;
        }
    }
    

    cout << "\nMAHASISWA DENGAN IPK TERTINGGI\n";
    
    cout << "Nama : " << mhs[tertinggi].nama << endl;
    cout << "NIM  : " << mhs[tertinggi].nim << endl;
    cout << "IPK  : " << mhs[tertinggi].ipk << endl;
    
    return 0;
}