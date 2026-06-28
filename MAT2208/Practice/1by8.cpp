#include <bits/stdc++.h>
using namespace std;

float func(float x){
    return log(x);
}

float simpsons1by8(float ll,float ul,int n){
    float res = 0;

    float h = (ul-ll)/n;
    float fx[10],f[10];

    for (int i=0;i<=n;i++){
        f[i]=ll+i*h;
        fx[i]=func(f[i]);
    }

    for (int i=0;i<=n;i++){
        if(i == 0 || i == n){
         res += fx[i];
        }
        else if(i%2 != 0){
            res += 4 * fx[i];
        }
        else {
            res += 2 * fx[i];
        }
    }

    return res = res * (h/3);

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

    


    cout << "Answer : " << simpsons1by8(ll,ul,n) ;
    
}