#include <iostream>
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
vector<int> mst;

int main(int argc, char const *argv[]) {
    cin >> nV >> nE;
    edgesFrom.resize(nV);
    edges.resize(nE);
    return 0;
}

void prim(int initial) {
    vector<bool> visited(nV, false);
    visited[initial] = true;
    priority_queue<Edge> pq;
    pq.push({0, -1, initial});
    while (!pq.empty()) {
        Edge nearest = pq.top();
        int v = nearest.to;
        if (!visited[v]) {
            mst[v] = nearest.fr;
            for (Edge &e: edgesFrom[v])
                if (visited[v]) 
        }
    }    
}