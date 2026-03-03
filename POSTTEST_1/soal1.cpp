#include <iostream>
using namespace std;
/*
ANALISIS KOMPLEKSITAS ALGORITMA
PSEUDOCODE

procedure FindMin(A : array of n elements)
min ← A[0]
  for i ← 1 to n − 1 do
    if A[i] < min then
      min ← A[i]
    end if
  end for
  return min
end procedure

baris = 9

TABEL PSEUDOCODE          DAN              COST
==========================================|
procedure FindMin(A : array of n elements)|C1
min ← A[0]                                |C2
for i ← 1 to n − 1 do                     |C3
if A[i] < min then                        |C4
min ← A[i]                                |C5
end if                                    |C6
end for                                   |C7
return min                                |C8
end procedure                             |C9


HITUNG Tmin dan Tmax
BEST CASE 
 rumus Tmin = C1(1) + C2(1) + C3(n) + C4(n-1) + C5(0) + C6(n-1) + C7(n) + C8(1) + C9(1)
 untuk n = 8
Tmin(8) = C1(1) + C2(1) + C3(8) + C4(7) + C5(0) + C6(7) + C7(8) + C8(1) + C9(1)
        = C1 + C2 + 8C3 + 7C4 + 0 + 7C6 + 8C7 + C8 + C9

 bentuk umum n Tmin(n) = (C1 + C2 + C8 + C9) + (C3 + C7)n + (C4 + C6)(n-1)
        = (C1 + C2 + C8 + C9) + (C3 + C7)n + (C4 + C6)n - (C4 + C6)
        = [(C3 + C7 + C4 + C6)]n + (C1 + C2 + C8 + C9 - C4 - C6)
        = A·n + B
        Big-O: O(n)
WORST CASE
rumus Tmax Tmax = C1(1) + C2(1) + C3(n) + C4(n-1) + C5(n-1) + C6(n-1) + C7(n) + C8(1) + C9(1)
      untuk n =8
      Tmax(8) = C1(1) + C2(1) + C3(8) + C4(7) + C5(7) + C6(7) + C7(8) + C8(1) + C9(1)
        = C1 + C2 + 8C3 + 7C4 + 7C5 + 7C6 + 8C7 + C8 + C9

 bentuk umum n Tmax(n) = (C1 + C2 + C8 + C9) + (C3 + C7)n + (C4 + C5 + C6)(n-1)
        = (C1 + C2 + C8 + C9) + (C3 + C7)n + (C4 + C5 + C6)n - (C4 + C5 + C6)
        = [(C3 + C7 + C4 + C5 + C6)]n + (C1 + C2 + C8 + C9 - C4 - C5 - C6)
        = C·n + D
        Big-O: O(n)

*/









int findMin(int A[], int n, int &minIndex) {
    int min = A[0];
    minIndex = 0;
    
    for (int i = 1; i < n; i++) {
        if (A[i] < min) {
            min = A[i];
            minIndex = i;
        }
    }
    return min;
}

int main() {
    int arr[] = {1, 1, 2, 3, 5, 8, 13, 21};
    int n = sizeof(arr) / sizeof(arr[0]);
    int index;
    
    int minValue = findMin(arr, n, index);
    
    cout << "Nilai minimum: " << minValue << endl;
    cout << "Berada pada index: " << index << endl;
    
    return 0;
}