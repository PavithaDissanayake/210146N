#include <iostream>
#include <list>

using namespace std;

struct Node {
    int label;
    list<int> neighbours;
};

struct Graph {
    int n = 8;
    Node* nodes = new Node[n+1];

    void initializeNodes() {
        for (int i = 1; i < n+1; i++) {
            nodes[i].label = i;
        }
    }

    void addEdge(int u, int v) {
        nodes[u].neighbours.push_back(v);
        nodes[v].neighbours.push_back(u);
    }

    void print() {
        for (int i = 1; i < n+1; i++) {
            cout << "Node " << nodes[i].label << ": ";
            for (int neighbour : nodes[i].neighbours) {
                cout << neighbour << " ";
            }
            cout << endl;
        }
    }
};

int main() {
    Graph* g = new Graph;
    g->initializeNodes();

    g->addEdge(1, 2);
    g->addEdge(1, 3);
    g->addEdge(1, 4);
    g->addEdge(1, 5);
    g->addEdge(2, 3);
    g->addEdge(2, 6);
    g->addEdge(4, 6);
    g->addEdge(4, 7);
    g->addEdge(4, 8);
    g->addEdge(5, 6);
    g->addEdge(5, 7);
    g->addEdge(5, 8);

    g->print();
}
