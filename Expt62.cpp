#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Graph {
public:
    int V;  
    vector<vector<int>> adjList;

    Graph(int vertices) : V(vertices), adjList(vertices) {}

    void addEdge(int v, int w) {
        adjList[v].push_back(w);
    }

    void BFS(int start) {
        
        vector<bool> visited(V, false);

       
        queue<int> q;
 
        visited[start] = true;
        q.push(start);

        while (!q.empty()) {
             
            int current = q.front();
            cout << current << " ";
            q.pop();

             
            for (int adjacent : adjList[current]) {
                if (!visited[adjacent]) {
                    
                    visited[adjacent] = true;
                    q.push(adjacent);
                }
            }
        }
    }
};

int main() {
    Graph graph(6);

    graph.addEdge(0, 1);
    graph.addEdge(0, 2);
    graph.addEdge(1, 3);
    graph.addEdge(2, 4);
    graph.addEdge(2, 5);

    cout << "Breadth-First Search (starting from vertex 0): ";
    graph.BFS(0);

    return 0;
}
