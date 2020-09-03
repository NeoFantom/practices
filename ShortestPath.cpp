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
vector<vector<Edge>> edgesFrom;
vector<Edge> edges;
vector<int> dist;
vector<vector<int>> allDist;
vector<int> predecessor;

int main(int argc, char const *argv[]) {
    cin >> nV >> nE;
    edgesFrom.resize(nV);
    edges.resize(nE);
    dist.resize(nV);
    predecessor.resize(nV);
    return 0;
}

void dijkstra(int s) {
    dist[s] = 0;
    predecessor[s] = -1;

    priority_queue<Edge> pq;
    vector<bool> visited(nV, false);
    visited[s] = true;

    int v = s;
    for (int _i = 0; _i < nV; ++_i) {
        for (Edge &e : edgesFrom[v]) {
            if (!visited[e.to] && dist[v] + e.w < dist[e.to]) {
                dist[e.to] = dist[v] + e.w;
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
        predecessor[nearest.to] = nearest.fr;
        v = nearest.to;
        visited[v] = true;
    }
}

void dijkstra_simplified(int s) {
    dist[s] = 0;
    predecessor[s] = -1;

    priority_queue<Edge> pq;
    vector<bool> visited(nV, false);
    visited[s] = false;

    pq.push({0, -1, s});
    while (!pq.empty()) {
        const Edge nearest = pq.top();
        pq.pop();
        int v = nearest.to;
        if (!visited[v]) {
            dist[v] = nearest.w;
            predecessor[v] = nearest.fr;
            for (Edge &e : edgesFrom[v]) {
                if (!visited[e.to] && dist[e.fr] + e.w < dist[e.to]) {
                    dist[e.to] = dist[e.fr] + e.w;
                    pq.push(e);
                }
            }
        }
    }
    for (bool vertexVisited : visited)
        if (!vertexVisited) exit(1); // Not connected
}

// Complexity: O(VE)
bool bellmanFord(int s) {
    dist[s] = 0;
    predecessor[s] = -1;
    for (int _i = 0; _i < nV - 1; ++_i)
        for (Edge &e : edges)
            if (dist[e.fr] + e.w < dist[e.to]) {
                dist[e.to] = dist[e.fr] + e.w;
                predecessor[e.to] = e.fr;
            }
    for (Edge &e : edges)
        if (dist[e.fr] + e.w < dist[e.to]) return false;
    return true;
}

// Complexity: O(kE) with k<5 normally
bool spfa(int s) {
    dist[s] = 0;
    predecessor[s] = -1;
    queue<int> Q;
    vector<bool> inQ(nV, false);
    vector<int> count(nV, 0);

    Q.push(s);
    while (!Q.empty()) {
        int v = Q.front();
        Q.pop();
        inQ[v] = false;
        for (Edge &e : edgesFrom[v]) {
            if (dist[v] + e.w < dist[e.to]) {
                dist[e.to] = dist[v] + e.w;
                predecessor[e.to] = v;

                if (!inQ[e.to]) {
                    Q.push(e.to);
                    ++count[e.to];
                    if (count[e.to] >= v) return false;
                }
            }
        }
    }
}

void floyd() {
    for (int mid = 0; mid < nV; ++mid)
        for (int from = 0; from < nV; ++from)
            for (int to = 0; to < nV; ++to)
                if (allDist[from][mid] + allDist[mid][to] < allDist[from][to]) {
                    allDist[from][to] = allDist[from][mid] + allDist[mid][to];
                }
}