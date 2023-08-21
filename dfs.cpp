#include <iostream>

#include "datastructures.h"
using namespace std;


template<typename T>
class Graph {
private:
    AdjacencyMatrix<T> adjMatrix;

public:
    Graph(int size) : adjMatrix(size) {}

    void addEdge(int row, int col, const T& weight) {
        adjMatrix.setEdge(row, col, weight);
    }

    void dfs(int startVertex, bool visited[]) {
        visited[startVertex] = true;
        cout << startVertex << " ";

        for (int i = 0; i < adjMatrix.getSize(); i++) {
            T edgeWeight = adjMatrix.getEdge(startVertex, i);
            if (!visited[i] && edgeWeight != T()) {
                dfs(i, visited);
            }
        }
    }

    void dfsTraversal() {
        bool *visited = new bool[adjMatrix.getSize()];
        for (int i = 0; i < adjMatrix.getSize(); i++) {
            visited[i] = false;
        }

        for (int i = 0; i < adjMatrix.getSize(); i++) {
            if (!visited[i]) {
                dfs(i, visited);
            }
        }

        delete[] visited;
    }
};

int main() {
    int size;
    cout << "Enter the size of the graph: ";
    cin >> size;

    Graph<int> graph(size);

    int edges;
    cout << "Enter the number of edges: ";
    cin >> edges;

    cout << "Enter edge information (source destination weight):" << endl;
    for (int i = 0; i < edges; i++) {
        int source, destination, weight;
        cin >> source >> destination >> weight;
        graph.addEdge(source, destination, weight);
    }

    int startVertex;
    cout << "Enter the starting vertex for DFS: ";
    cin >> startVertex;

    cout << "DFS traversal starting from vertex " << startVertex << ": ";
    graph.dfsTraversal();
    cout << endl;

    return 0;
}

