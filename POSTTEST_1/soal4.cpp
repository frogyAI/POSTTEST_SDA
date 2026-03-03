#include <iostream>
using namespace std;


void tukarNilaiPointer(int *a, int *b) {
    int temp = *a;
    *a = *b;        
    *b = temp;      
}

int main() {
    int x, y;
    
    cout << "Masukkan nilai x: ";
    cin >> x;
    cout << "Masukkan nilai y: ";
    cin >> y;
    
    cout << "\nSebelum ditukar: x = " << x << ", y = " << y << endl;
    
    
    tukarNilaiPointer(&x, &y);
    cout << "Setelah ditukar: x = " << x << ", y = " << y << endl;
    
    return 0;
}