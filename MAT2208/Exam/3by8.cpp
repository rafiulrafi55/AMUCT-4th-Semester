#include <bits/stdc++.h>
using namespace std;

float func(float x){
    return 1/(1+x*x);
}

float simpsons3by8(float ll,float ul,int n){
    float sum = 0.0;
    float h = ((ul-ll)/n);
    sum = func(ul) + func(ll);
    for(int i = 1;i<n;i++){
        if (i%3 == 0){
            sum += 2 * func(ll + i * h);
        }
        else {
            sum += 3 * func(ll+i * h);
        }
    }

    return sum * (3*h/8);
}

int main(){
    float ll,ul;
    int n;
    bool isSmall = true;
    
    if (ll>ul){
        isSmall = false;
        while (!isSmall){
            ll = 0;
            ul = 0;
        cout << "Lower limit cannot be greater than Upper Limit\n";
        cout << "Input Lower Limit : " ;
        cin >> ll ;
        cout << "Input Upper Limit : ";
        cin >> ul;
        
        
        if(ul>ll){
            isSmall = true;
        }
    }
    }
    cout << "Input interval : ";
    cin >> n;

    


    cout << "Answer : " << simpsons3by8(ll,ul,n) ;
    
}