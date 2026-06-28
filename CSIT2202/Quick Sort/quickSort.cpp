#include <bits/stdc++.h>
using namespace std;

// Quick Sort - Unstable & in-place algorithm

int Partition(int* A, int start, int finish) {
    int pivot = A[finish];
    int pIndex = start;
    
    for (int i=start; i<finish; i++) {
        if (A[i] <= pivot) {
            swap(A[i], A[pIndex]);
            pIndex++;
        }
    }
    
    swap(A[pIndex], A[finish]);
    return pIndex;
}

void QuickSort(int* A, int start, int finish) {
    if (start < finish) {
        int pIndex = Partition(A, start, finish);
        QuickSort(A, start, pIndex - 1);
        QuickSort(A, pIndex + 1, finish);
    }
}

int main() {
	
	int A[] = {2, 4, 1, 7, 6, 8, 5, 3};
	
	int n = sizeof(A) / sizeof(int);
	
	QuickSort(A, 0, n-1);
	
	for (int i=0; i<n; i++) cout << A[i] << " ";
	cout << endl;
	
    return 0;
}