#include <bits/stdc++.h>

using namespace std;

bool isPrime(int n) {
    if (n <= 1) return false;
    for (int i = 2; i <= sqrt(n); i++) {
        if (n % i == 0) return false;
    }
    return true;
}

int sumOfElements(int arr[],int n){
    int sum = 0;
    for(int i = 0; i<n; i++){
        sum += arr[i];
    }
    return sum;
}
int main() {

    time_t startTime, endTime;
    int n;
    // cout << "Enter a number: ";
    // cin >> n;
    // time(&startTime);
    // if (isPrime(n)) {
    //     cout << n << " is a prime" << endl;
    // } else {
    //     cout << n << " is not a prime" << endl;
    // }
    cout << "Enter array size : ";
    cin >> n;
    int arr[n];
    cout << "Enter array elements : ";
    for(int i = 0; i<n; i++){
        cin >> arr[i];
    }
    int sum = sumOfElements(arr,n);
    cout << "Sum of array elements is : " << sum << endl;

    time(&endTime);
    cout << "Time taken: " << difftime(startTime, endTime) << " seconds" << endl;
    return 0;
}
