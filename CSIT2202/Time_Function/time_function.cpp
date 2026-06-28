#include<bits/stdc++.h>
#include<time.h>
using namespace std;

typedef long long int LL;

void func(LL n) {
    LL k = 0;
    while (k <= n) k++;
}

int main() {
    
    time_t startTime, endTime;
    LL inp;
    printf("Enter no. of instructions: ");
    scanf("%lld", &inp);
    
    time(&startTime);
    func(inp);
    time(&endTime);
    
    printf("Time in seconds: %.20lf\n", (double)(endTime - startTime));
    
    return 0;
}