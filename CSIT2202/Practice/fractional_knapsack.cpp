#include<bits/stdc++.h>
using namespace std;

struct Item {
    float weight;
    float profit;

    Item(float w,float p){
        weight = w;
        profit = p;
    }
};

bool compare(Item a,Item b){
    float r1 = a.profit / a.weight;
    float r2 = b.profit / b.weight;
    return (r1 > r2) ;
}

void fracKnap(vector<Item>& items,float capacity){
    sort(items.begin(),items.end(),compare);

    float max_profit = 0.0f;
    for(auto& i:items){
        if(i.weight <= capacity){
            capacity = capacity - i.weight;
            max_profit += i.profit;
        }
        else{
            max_profit += i.profit * (capacity/i.weight);
            break;
        }
    }

    cout << "\n\nMax Profit : " << max_profit << endl;
}

int main(){
    int n;
    cout << "How many items ? : " ;
    cin >> n;

    vector<Item> items;
    items.reserve(n);
    int i = 0;

    while(i<n){
        float w = 0.0f;;
        cout << "Input weight of item " << i+1 << " : ";
        cin >> w;
        float p = 0.0f;
        cout << "Input profit of item " << i+1 << " : ";
        cin >> p;

        items.emplace_back(w,p);
        i++;
    }

    float capacity = 0.0f;
    cout << "Input Capacity : ";
    cin >> capacity;

    fracKnap(items,capacity);
    return 0;




}