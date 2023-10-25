#include <iostream>
#include <vector>

using namespace std;

class Graph {
public:
    int V;  
    vector<vector<int>> adjList;

    Graph(int vertices) : V(vertices), adjList(vertices) {}

    void addEdge(int v, int w) {
        adjList[v].push_back(w);
    }

    void DFSUtil(int v, vector<bool>& visited) {
        visited[v] = true;
        cout << v << " ";

        for (int adjacent : adjList[v]) {
            if (!visited[adjacent]) {
                DFSUtil(adjacent, visited);
            }
        }
    }

    void DFS(int start) {
        vector<bool> visited(V, false);

        cout << "Depth-First Search starting from vertex " << start << ": ";
        DFSUtil(start, visited);
    }
};

int main() {
    Graph graph(7);

    graph.addEdge(0, 1);
    graph.addEdge(0, 2);
    graph.addEdge(1, 3);
    graph.addEdge(1, 4);
    graph.addEdge(2, 5);
    graph.addEdge(2, 6);

    graph.DFS(0);

    return 0;
}
