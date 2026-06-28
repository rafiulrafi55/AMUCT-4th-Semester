#include<bits/stdc++.h>
using namespace std;

struct Edge {
    int source;
    int destination;
    int weight;
};

int main() {

    vector<Edge> edgeList;

    int E;
    cout << "How many edges ?: ";
    cin >> E;

    bool undir;

    cout << "Undirected ? (0/1): ";
    cin >> undir;

    int s, d, w;
    while (E--) {
        cout << "Enter source: ";
        cin >> s;
        cout << "Enter destination: ";
        cin >> d;
        cout << "Enter weight: ";
        cin >> w;
        edgeList.push_back({s, d, w});
        if (undir)
            edgeList.push_back({d, s, w});
    }


    cout << "Edge List:\n";
    for (auto& e : edgeList)
        cout << e.source << " -> " << e.destination << ": " << e.weight << endl;

    return 0;
}
