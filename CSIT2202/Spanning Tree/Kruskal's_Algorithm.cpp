#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Structure to represent a graph edge
struct Edge {
    int source, destination, weight;
};

// Structure for a disjoint set (for Union-Find)
struct DisjointSet {
    int *parent;
    DisjointSet(int n) {
        parent = new int[n];
        for (int i = 0; i < n; i++)
            parent[i] = i; // Each vertex is its own parent initially
    }

    // Find the parent of a vertex (with path compression)
    int find(int i) {
        if (parent[i] == i)
            return i;
        return parent[i] = find(parent[i]);
    }

    // Union of two sets
    void unite(int x, int y) {
        int rootX = find(x);
        int rootY = find(y);
        if (rootX != rootY) {
            parent[rootX] = rootY;
        }
    }
};

class Graph {
private:
    int V; // Number of vertices
    vector<Edge> edges; // Vector to store all edges

public:
    Graph(int vertices) {
        V = vertices;
    }

    void addEdge(int u, int v, int w) {
        edges.push_back({u, v, w});
    }

    // Comparison function to sort edges by weight
    static bool compareEdges(const Edge& a, const Edge& b) {
        return a.weight < b.weight;
    }

    void kruskalMST() {
        vector<Edge> result; // This will store the resultant MST
        int edgeCount = 0;
        int i = 0;

        // Step 1: Sort all the edges in non-decreasing order of their weight
        sort(edges.begin(), edges.end(), compareEdges);

        DisjointSet ds(V);

        // Iterate through all sorted edges
        while (edgeCount < V - 1 && i < edges.size()) {
            Edge next_edge = edges[i++];

            int rootSource = ds.find(next_edge.source);
            int rootDest = ds.find(next_edge.destination);

            // If including this edge doesn't cause a cycle
            if (rootSource != rootDest) {
                result.push_back(next_edge);
                ds.unite(rootSource, rootDest);
                edgeCount++;
            }
        }

        // Print the constructed MST
        cout << "Edge \tWeight\n";
        int totalWeight = 0;
        for (const auto& edge : result) {
            cout << edge.source << " - " << edge.destination << "\t" << edge.weight << endl;
            totalWeight += edge.weight;
        }
        cout << "Total weight of MST: " << totalWeight << endl;
    }
};

int main() {
    int V = 4;
    Graph g(V);

    g.addEdge(0, 1, 10);
    g.addEdge(0, 2, 6);
    g.addEdge(0, 3, 5);
    g.addEdge(1, 3, 15);
    g.addEdge(2, 3, 4);

    g.kruskalMST();

    return 0;
}