#include <algorithm>
#include <cstdio>
#include <iostream>
#include <queue>
#include <stack>
#include <vector>

using namespace std;

struct Edge {
    int w;
    int fr, to;
    friend bool operator<(const Edge &e, const Edge &f) { return e.w > f.w; }
};

int nV, nE;
vector<vector<Edge>> edges;
vector<Edge> path;

void dijkstra(int s) {
    priority_queue<Edge> pq;
    vector<bool> visited(nV, false);
    visited[s] = true;
    vector<int> dist(nV, 0x4fffffff);
    dist[s] = 0;

    int v = s;
    path.push_back({0, s});
    while (path.size() != nV) {
        for (Edge &e : edges[v]) {
            if (!visited[e.to]) {
                dist[e.to] = min(dist[e.to], dist[v] + dist[e.w]);
                pq.push({dist[e.to], e.fr, e.to});
            }
        }
        Edge nearest;
        do {
            if (pq.empty()) {
                exit(1);  // Not connected;
            } else {
                nearest = pq.top();
                pq.pop();
            }
        } while (visited[nearest.to]);
        path.push_back(nearest);
        v = nearest.to;
        visited[v] = true;
    }
}



void spfa(int s) {
    priority_queue<Edge> pq;
    vector<bool> visited(nV, false);
    visited[s] = true;
    vector<int> dist(nV, 0x4fffffff);
    dist[s] = 0;

}

int main(int argc, char const *argv[]) {
    ;
    return 0;
}
