#include <iostream>
#include <vector>
#include <climits>

using namespace std;

#define V 6

int findMinKey(const vector<int>& key, const vector<bool>& mstSet)
{
    int minKey = INT_MAX;
    int minIndex;

    for (int v = 0; v < V; ++v) {
        if (mstSet[v] == false && key[v] < minKey) {
            minKey = key[v];
            minIndex = v;
        }
    }

    return minIndex;
}

void primMST(const vector<vector<int>>& graph)
{
    vector<int> parent(V);
    vector<int> key(V);
    vector<bool> mstSet(V, false);

    for (int i = 0; i < V; ++i) {
        key[i] = INT_MAX;
    }

    key[0] = 0;
    parent[0] = -1;

    for (int count = 0; count < V - 1; ++count) {
        int u = findMinKey(key, mstSet);
        mstSet[u] = true;

        for (int v = 0; v < V; ++v) {
            if (graph[u][v] && mstSet[v] == false && graph[u][v] < key[v]) {
                parent[v] = u;
                key[v] = graph[u][v];
            }
        }
    }

    cout << "Edge \tWeight\n";
    for (int i = 1; i < V; ++i) {
        cout << parent[i] << " - " << i << "\t" << graph[i][parent[i]] << "\n";
    }
}

int main()
{
    vector<vector<int>> graph = {
        {0, 3, 0, 0, 0, 1 },
        {3, 0, 2, 1, 10, 0},
        {0, 2, 0, 3, 0, 5},
        {0, 1, 3, 0, 5, 0},
        {0, 10, 0, 5, 0, 4},
        {1, 0, 5, 0, 4, 0}
    };

    primMST(graph);

    return 0;
}
