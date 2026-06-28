#include<bits/stdc++.h>
using namespace std;

class Graph {
private:
	int n; // no. of vertices
	vector<vector<pair<int,int> > > adjList; // Adjacency List with weights (neighbor, weight)
	set<pair<int,int> > edges; // Store edges to detect duplicates (sorted pairs for undirected)

public:
	Graph(int V) {
		n = V;
		adjList.resize(n);
	}

	bool edgeExists(int source, int destination) {
		int u = min(source, destination);
		int v = max(source, destination);
		return edges.count({u, v}) > 0;
	}

	bool addEdge(int source, int destination, int weight, bool undir = true) {
		int u = min(source, destination);
		int v = max(source, destination);
		
		if (edgeExists(source, destination))
			return false; // Edge already exists
		
		edges.insert({u, v});
		adjList[source].push_back({destination, weight});
		if (undir)
			adjList[destination].push_back({source, weight});
		return true;
	}

	void bfs(int start) {
		vector<bool> visited(n, false);
		queue<int> q;

		visited[start] = true;
		q.push(start);

		cout << "BFS Traversal: ";

		while (!q.empty()) {
			int node = q.front();
			q.pop();
			cout << node << " ";

			for (const auto &p : adjList[node]) {
				int neighbor = p.first;
				int w = p.second;
				if (!visited[neighbor]) {
					visited[neighbor] = true;
					q.push(neighbor);
				}
			}
		}

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
	int edgesAdded = 0;

	while (edgesAdded < E) {
		cout << "Enter source: ";
		cin >> source;
		cout << "Enter destination: ";
		cin >> destination;
		cout << "Enter weight: ";
		cin >> weight;
		
		if (g.addEdge(source, destination, weight)) {
			edgesAdded++;
		} else {
			cout << "ERROR: Edge (" << source << "-" << destination << ") already exists! Please enter a different edge\n";
		}
	}

	int start;
	cout << "Enter starting vertex for BFS: ";
	cin >> start;

	g.bfs(start);

	return 0;
}
