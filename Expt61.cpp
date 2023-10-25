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
        adjList[w].push_back(v);  
    }

  
    void printGraph() {
        for (int i = 0; i < V; i++) {
            cout << "Adjacency list of vertex " << i << ": ";
            for (int j : adjList[i]) {
                cout << j << " ";
            }
            cout << endl;
        }
    }
};

int main() {
    
    Graph graph(5);

     
    graph.addEdge(0, 1);
    graph.addEdge(0, 4);
    graph.addEdge(1, 2);
    graph.addEdge(1, 3);
    graph.addEdge(1, 4);
    graph.addEdge(2, 3);
    graph.addEdge(3, 4);

   
    graph.printGraph();

    return 0;
}
