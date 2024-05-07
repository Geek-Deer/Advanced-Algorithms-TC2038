#include <iostream>
#include <vector>
#include <queue>

using namespace std;

const int V = 6;

int min(int a, int b) { return (a < b)? a: b; }

int bfs(int rGraph[V][V], int s, int t, int parent[]) {
    vector<int> visited(V, 0);
    queue<int> q;
    q.push(s);
    visited[s] = 1;
    parent[s] = -1;

    while (!q.empty()) {
        int u = q.front();
        q.pop();

        for (int v=0; v<V; v++) {
            if (visited[v] == 0 && rGraph[u][v] > 0) {
                q.push(v);
                parent[v] = u;
                visited[v] = 1;

                if (v == t)
                    return true;
            }
        }
    }

    return false;
}

int fordFulkerson(int graph[V][V], int s, int t) {
    int u, v;

    int rGraph[V][V];

    for (u = 0; u < V; u++)
        for (v = 0; v < V; v++)
            rGraph[u][v] = graph[u][v];

    int parent[V];
    int max_flow = 0;

    while (bfs(rGraph, s, t, parent)) {
        int path_flow = INT_MAX;
        for (v = t; v != s; v = parent[v]) {
            u = parent[v];
            path_flow = min(path_flow, rGraph[u][v]);
        }

        for (u = t; u != s; u = parent[u]) {
            v = parent[u];
            rGraph[u][v] -= path_flow;
            rGraph[v][u] += path_flow;
        }

        max_flow += path_flow;
    }

    return max_flow;
}

int main() {
    int graph[V][V] = { {0, 16, 13, 0, 0, 0},
                        {0, 0, 10, 12, 0, 0},
                        {0, 4, 0, 0, 14, 0},
                        {0, 0, 9, 0, 0, 20},
                        {0, 0, 0, 7, 0, 4},
                        {0, 0, 0, 0, 0, 0} };

    cout << "El flujo máximo es " << fordFulkerson(graph, 1, 3);

    return 0;
}
