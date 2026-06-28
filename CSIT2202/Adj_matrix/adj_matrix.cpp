#include<bits/stdc++.h>
using namespace std;

class Graph {
    // Attributes = variables
    // Methods = Functions
private:
    int n; // no. of vertices
    vector<vector<int> > adjMatrix; // Adjacency Matrix
public:
    Graph(int V) {
        n = V; // assign no. of vertices
        adjMatrix.resize(n); // resize rows

        for (int i=0; i<n; i++)
            adjMatrix[i].resize(n); // resize columns

        cout << "Matrix Created!!!\n";
    }

    void addEdge(int source, int destination, int weight, bool undir = true) {
        adjMatrix[source][destination] = weight;
        if (undir)
            adjMatrix[destination][source] = weight;
    }

    void printMatrix() {
        cout << "    ";
        for (int i=0; i<n; i++) cout << i << " ";
        cout << "\n____________\n";
        for (int i=0; i<n; i++) {
            cout << i << " | ";
            for (int j=0; j<n; j++)
                cout << adjMatrix[i][j] << " ";
            cout << endl;
        }
    }
};

int main() {
    int V, E;
    cout << "How many vertices ? : ";
    cin >> V;

    Graph g(V);

    cout << "How many edges ? : ";
    cin >> E;

    int s, d, w;

    while (E--) {
        cout << "Enter source: ";
        cin >> s;
        cout << "Enter destination: ";
        cin >> d;
        cout << "Enter weight: ";
        cin >> w;
        g.addEdge(s, d, w);
    }

//    g.addEdge(0, 1, 3);
//    g.addEdge(0, 2, 1);
//    g.addEdge(1, 2, 5);
//    g.addEdge(2, 3, 4);
//    g.addEdge(1, 3, 2);

    g.printMatrix();

    return 0;
}
