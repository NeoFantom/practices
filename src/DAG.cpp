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
vector<int> predecessor;

vector<int> inDegree;
void calculateInDegree() {
    for (int i = 0; i < nV; ++i)
        for (Edge &e : edgesFrom[i]) inDegree[e.to]++;
}

vector<int> topologicalVertices;
void topologicalOrder() {
    calculateInDegree();

    queue<int> q;
    for (int v = 0; v < nV; ++v)
        if (inDegree[v] == 0) q.push(v);

    for (int _i = 0; _i < nV; ++_i) {
        int v = q.front();
        q.pop();
        topologicalVertices.push_back(v);
        for (Edge &e : edgesFrom[v]) {
            inDegree[e.to]--;
            if (inDegree[e.to] == 0) q.push(e.to);
        }
    }
}

vector<int> maxTail(nV, 0);
vector<int> maxNext(nV, 0);
vector<bool> done(nV, false);
int longestPathFrom(int start) {
    int max = 0;
    int maxv;
    for (Edge &e : edgesFrom[start]) {
        if (!done[e.to]) longestPathFrom(e.to);
        if (max < maxTail[e.to]) {
            max = maxTail[e.to];
            maxv = e.to;
        }
    }
    maxTail[start] = max;
    maxNext[start] = maxv;
}

int main(int argc, char const *argv[]) {
    cin >> nV >> nE;
    edgesFrom.resize(nV);
    edges.resize(nE);
    predecessor.resize(nV);
    maxTail.resize(nV);
    maxNext.resize(nV);
    return 0;
}