#include <bits/stdc++.h>
using namespace std;

// Merge Sort - Stable & out-of-place algorithm

// A = main array
// n =  main array size
// L = left array
// nL =  left array size
// R = right array
// nR =  right array size

void Merge(int* A, int n, int* L, int nL, int* R, int nR) { 
    int i, j, k;
    i = j = k = 0;
    
    while (i < nL && j < nR) {
        if (L[i] <= R[j]) {
            A[k] = L[i];
            i++;
        } else {
            A[k] = R[j];
            j++;
        }
        k++;
    }
    
    while (i < nL) {
        A[k] = L[i];
        i++;
        k++;
    }
    
    while (j < nR) {
        A[k] = R[j];
        j++;
        k++;
    }
}

void MergeSort(int* A, int n) {
    if (n < 2) return;
    
    int half = n / 2;
    
    int L[half], R[n-half];
    
    for (int i=0; i<half; i++) L[i] = A[i];
    
    for (int i=half; i<n; i++) R[i-half] = A[i];
    
    MergeSort(L, half);
    MergeSort(R, n-half);
    Merge(A, n, L, half, R, n-half);
}

int main() {
	
	int A[] = {2, 4, 1, 7, 6, 8, 5, 3};
	
	int n = sizeof(A) / sizeof(int);
	
	MergeSort(A, n);
	
	for (int i=0; i<n; i++) cout << A[i] << " ";
	cout << endl;
	
    return 0;
}