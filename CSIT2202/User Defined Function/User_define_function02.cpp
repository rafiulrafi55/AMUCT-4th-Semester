#include <bits/stdc++.h>
using namespace std;

bool isPrime(int n) {
    for (int i=2; i*i<n; i++) {
        if (n % i == 0) return false;
    }
    return true;
}

int sumOfArray(int* arr, int n) {
    int sum = 0;
    for (int i=0; i<n; i++) sum = sum + arr[i];
    
    return sum;
}

int GCD1(int a, int b) {
    int res = 0;
    for (int i=1; i<=min(a,b); i++) {
        if (a % i == 0 && b % i == 0 && i > res) res = i;
    }
    
    return res;
}

int GCD2(int a, int b) {
    if (a % b == 0) return b;
    return GCD2(b, a%b);
}

int main() {
    
    // take input from user and call your desired function
    int n;
    cout << "Enter a number: ";
    cin >> n;
    if (isPrime(n)) {
        cout << n << " is a prime" << endl;
    } 
    else {
        cout << n << " is not a prime" << endl;
    }
	
    return 0;
}