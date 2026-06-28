#include<bits/stdc++.h>
using namespace std;

class Graph {
private:
	int n; // no. of vertices
	vector<vector<pair<int,int> > > adjList; // Adjacency List with weights (neighbor, weight)

	void dfsHelper(int node, vector<bool> &visited) {
		visited[node] = true;
		cout << node << " ";

		for (const auto &p : adjList[node]) {
			int neighbor = p.first;
			if (!visited[neighbor])
				dfsHelper(neighbor, visited);
		}
	}

public:
	Graph(int V) {
		n = V;
		adjList.resize(n);
	}

	void addEdge(int source, int destination, int weight, bool undir = true) {
		adjList[source].push_back({destination, weight});
		if (undir)
			adjList[destination].push_back({source, weight});
	}

	void dfs(int start) {
		vector<bool> visited(n, false);
		cout << "DFS Traversal: ";
		dfsHelper(start, visited);
		cout << endl;
	}
};

int main() {
	int V, E;

	cout << "How many vertices ? : ";
	cin >> V;

	Graph g(V);

	cout << "How many edges ? : ";
	cin >> E;

	int source, destination, weight;

	while (E--) {
		cout << "Enter source: ";
		cin >> source;
		cout << "Enter destination: ";
		cin >> destination;
		cout << "Enter weight: ";
		cin >> weight;
		g.addEdge(source, destination, weight);
	}

	int start;
	cout << "Enter starting vertex for DFS: ";
	cin >> start;

	g.dfs(start);

	return 0;
}
