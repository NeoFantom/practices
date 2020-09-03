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
vector<Edge> mst;

int main(int argc, char const *argv[]) {
    cin >> nV >> nE;
    edgesFrom.resize(nV);
    edges.resize(nE);
    return 0;
}

void prim(int initial) {
    vector<bool> visited(nV, false);
    visited[initial] = true;
    int v = initial;
    for (int _i = 0; _i < nV; _i++) {
        for (Edge &e: edgesFrom[v])
        if (visited[e.to] && )
    }
}