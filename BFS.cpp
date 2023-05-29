#include <iostream>
#include <vector>
#include <deque>

class Graph {
private:
    int V;
    std::vector<std::vector<int>> adj;

public:
    Graph(int v) {
        V = v;
        adj.resize(v);
    }

    void addEdge(int v, int w) {
        adj[v].push_back(w);
    }

    void BFS(int s) {
        std::vector<bool> visited(V, false);
        BFSUtil(s, visited);
    }

private:
    void BFSUtil(int s, std::vector<bool>& visited) {
        std::deque<int> queue;
        visited[s] = true;
        queue.push_back(s);

        while (!queue.empty()) {
            s = queue.front();
            queue.pop_front();
            std::cout << s << " ";

            for (int n : adj[s]) {
                if (!visited[n]) {
                    visited[n] = true;
                    queue.push_back(n);
                }
            }
        }
    }
};

int main() {
    int n;
    std::cout << "Enter the size of the graph: ";
    std::cin >> n;

    Graph g(n);

    int size;
    std::cout << "Enter the size of input: ";
    std::cin >> size;

    for (int i = 0; i < size; i++) {
        std::cout << "Enter edges " << (i + 1) << " of graph: ";
        int j, k;
        std::cin >> j >> k;

        if (j < n && k < n) {
            g.addEdge(j, k);
        } else {
            std::cout << "Invalid Input\n";
        }
    }

    int start;
    std::cout << "Enter the starting vertex: ";
    std::cin >> start;

    std::cout << "BFS of Graph\n";
    g.BFS(start);

    return 0;
}

