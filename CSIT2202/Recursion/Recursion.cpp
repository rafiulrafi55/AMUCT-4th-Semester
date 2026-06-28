#include<bits/stdc++.h>
using namespace std;

int factorial(int n) {
    //cout << "I'm calculating ... f(" << n << ")\n";
    if (n == 0) return 1;

    int ans = n * factorial(n-1);
    //cout << "Calculation done!!! f(" << n << ") = " << ans << endl;

    return ans;
}

int fibonacci(int n) {

    if (n <= 1) return n;

    return fibonacci(n-1) + fibonacci(n-2);
}

int power(int a, int b) {

    if (b == 0) return 1;

    return a * power(a, b-1);
}

int SumOfDigits(int n) {

    if (n == 0) return 0;

    return (n%10) + SumOfDigits(n/10);
}

int GCD(int a, int b) {
    if (a % b == 0) return b;

    return GCD(b, a%b);
}

void printRange(int a, int b) {
    if (a > b) return;

    cout << a << " ";
    printRange(a+2, b);
}

void Reverse(string s, int idx) {
    if (idx < 0) return;

    cout << s[idx];
    Reverse(s, idx-1);
}

bool isPalindrome(string s, int i, int j) {
    if (i > j) return true;

    if (s[i] != s[j]) return false;

    return isPalindrome(s, i+1, j-1);
}

int binarySearch(int* arr, int key, int start, int finish) {
    if (start > finish) return -1;

    int mid = (start+finish) / 2;

    if (key == arr[mid]) return mid;

    if (key < arr[mid])
        return binarySearch(arr, key, start, mid-1);
    else
        return binarySearch(arr, key, mid+1, finish);
}

void Merge(int* A, int n, int* L, int nL, int* R, int nR) {
    int i, j, k;
    i = j = k = 0;

    while (i<nL && j<nR) {
        if (L[i] <= R[j]) {
            A[k] = L[i];
            i++;
        }
        else {
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

    int half = n/2;
    int L[half], R[n-half];

    for (int i=0; i<half; i++) L[i] = A[i];
    for (int i=half; i<n; i++) R[i-half] = A[i];

    MergeSort(L, half);
    MergeSort(R, n-half);
    Merge(A, n, L, half, R, n-half);
}

int main() {

    int arr[] = {2, 4, 7, 9, 6, 8, 5, 3, 1};
    int n = sizeof(arr) / sizeof(int);

    MergeSort(arr, n);

    for (int i:arr)
        cout << i << " ";
    cout << endl;

    return 0;
}
