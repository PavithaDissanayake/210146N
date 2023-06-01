#include <iostream>
#include <vector>
#include <queue>
#include <climits>

using namespace std;

typedef pair<int, int> pii;

void initializeSingleSource(vector<int>& distances, int source) { // setting initial values for the distances
    distances[source] = 0;
}

vector<int> dijkstra(vector<vector<int>>& graph, int source) {
    int n = graph.size();
    vector<int> distances(n, INT_MAX);
    vector<bool> visited(n, false);
    initializeSingleSource(distances, source);

    priority_queue<pii, vector<pii>, greater<pii>> pq; // proritiy queues to store vertices with their respective distances
    pq.push({0, source});

    while (!pq.empty()) {
        int current_node = pq.top().second;
        pq.pop();

        if (visited[current_node])
            continue;

        visited[current_node] = true;

        for (int neighbor = 0; neighbor < n; neighbor++) {
            if (graph[current_node][neighbor] != 0) {
                int edge_weight = graph[current_node][neighbor];

                int distance = distances[current_node] + edge_weight;
                if (distance < distances[neighbor]) {
                    distances[neighbor] = distance;
                    pq.push({distance, neighbor});
                }
            }
        }
    }

    return distances;
}

int main() {
    int n = 6;

    vector<vector<int>> graph = {
        {0, 10, 0, 0, 15, 5}, // adjacency matrix
        {10, 0, 10, 30, 0, 0},
        {0, 10, 0, 12, 5, 0},
        {0, 30, 12, 0, 0, 20},
        {15, 0, 5, 0, 0, 0},
        {5, 0, 0, 20, 0, 0,}
    };

    int source_node = 0;
    
    vector<int> shortest_distances = dijkstra(graph, source_node);

    cout << "Shortest distances from " << source_node << " to all other nodes:\n";
    for (int i = 0; i < n; i++) {
        cout << i << " : " << shortest_distances[i] << endl;
    }

    return 0;
}
