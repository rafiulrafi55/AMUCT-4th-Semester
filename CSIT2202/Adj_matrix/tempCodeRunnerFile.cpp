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