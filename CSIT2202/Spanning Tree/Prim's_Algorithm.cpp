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

    void primMST() {
       
   
        vector<int> parent(n, -1); // To store the MST
        vector<int> key(n, INT_MAX); // Key values used to pick minimum weight edge
        vector<bool> inMST(n, false); // To check if vertex is included in MST

        key[0] = 0; // Start from the first vertex
        parent[0] = -1; // First node is always the root of MST

        for (int count = 0; count < n - 1; count++) {
            int minKey = INT_MAX, minIndex;

            // Pick the minimum key vertex from the set of vertices not yet included in MST
            for (int v = 0; v < n; v++) {
                if (!inMST[v] && key[v] < minKey) {
                    minKey = key[v];
                    minIndex = v;
                }
            }

            inMST[minIndex] = true; // Add the picked vertex to the MST

            // Update the key value and parent index of the adjacent vertices of the picked vertex
            for (int v = 0; v < n; v++) {
                if (adjMatrix[minIndex][v] && !inMST[v] && adjMatrix[minIndex][v] < key[v]) {
                    parent[v] = minIndex;
                    key[v] = adjMatrix[minIndex][v];
                }
            }
        }

        // Print the constructed MST
        cout << "Edge \tWeight\n";
        for (int i = 1; i < n; i++)
            cout << parent[i] << " - " << i << "\t" << adjMatrix[parent[i]][i] << endl;
   
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

    g.primMST();

    return 0;
}