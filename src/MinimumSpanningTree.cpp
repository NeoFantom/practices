#include <algorithm>
#include <iostream>
#include <numeric>
#include <queue>
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
vector<int> predecessor;
int totalCost;

void prim(int initial) {
    predecessor[initial] = -1;
    vector<bool> visited(nV, false);
    vector<int> dist(nV, 0x4fffffff);
    visited[initial] = true;
    dist[initial] = 0;
    int v = initial;
    for (int _i = 0; _i < nV; ++_i) {
        for (Edge &e : edgesFrom[v])
            if (!visited[e.to] && dist[e.to] > e.w) {
                dist[e.to] = e.w;
                predecessor[e.to] = e.w;
            }
        int min = 0x4fffffff;
        for (int candidate = 0; candidate < nV; ++candidate)
            if (!visited[candidate] && dist[candidate] < min) {
                min = dist[candidate];
                v = candidate;
            }
        visited[v] = true;
    }
}

void prim_optimized(int initial) {
    predecessor[initial] = -1;
    vector<bool> visited(nV, false);
    priority_queue<Edge> pq;
    visited[initial] = true;
    pq.push({0, -1, initial});
    while (!pq.empty()) {
        Edge nearest = pq.top();
        pq.pop();
        int v = nearest.to;
        if (!visited[v]) {
            visited[v] = true;
            predecessor[v] = nearest.fr;
            totalCost += nearest.w;
            for (Edge &e : edgesFrom[v])
                if (!visited[v]) pq.push(e);
        }
    }
}

int _findRoot(vector<int> &component, int i) {
    int &root = component[i];
    if (component[root] == root) {
        return root;
    } else {
        root = _findRoot(component, root);
        return root;
    }
}

void kruskal(int initial) {
    predecessor[initial] = -1;
    vector<int> component(nV);
    priority_queue<Edge> pq(edges.begin(), edges.end());

    // If component[root]=root, then component[component[i]] is always valid.
    iota(component.begin(), component.end(), 0);
    while (!pq.empty()) {
        Edge e = pq.top();
        pq.pop();
        int rootFrom = _findRoot(component, e.fr);
        int rootTo = _findRoot(component, e.to);
        if (rootFrom != rootTo) {
            component[e.to] = e.fr;
            predecessor[e.to] = rootFrom;
        }
    }
}

int main(int argc, char const *argv[]) {
    cin >> nV >> nE;
    edgesFrom.resize(nV);
    edges.resize(nE);
    predecessor.resize(nV);
    totalCost = 0;
    return 0;
}