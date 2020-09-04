#include <cstdio>
#include <queue>
#include <stack>
#include <vector>

using namespace std;

int nV, nE;
vector<vector<int>> graph;
vector<bool> visited;
vector<int> trav;

void dfsRecBranch(int startFrom) {  // Traverse one connected branch
    for (int v : graph[startFrom]) {
        if (!visited[v]) {  // Every neighbour
            trav.push_back(v);
            dfsRecBranch(v);
        }
    }
}

void dfsBranch(int startFrom) {
    stack<int> stk;
    stk.push(startFrom);
    while (!stk.empty()) {
        int t = stk.top();
        stk.pop();
        trav.push_back(t);
        visited[t] = true;
        for (int v : graph[t])
            if (!visited[v]) stk.push(v);
    }
}

void bfsBranch(int startFrom) {
    trav.push_back(startFrom);
    int checking = 0;
    while (checking != trav.size()) {
        for (int v : graph[trav[checking]]) trav.push_back(v);
    }
}

void searchDisconnectedGraph(int startFrom) {
    // E.g. dfs
    dfsRecBranch(startFrom);
    for (int i = 0; i < nV; ++i)
        if (!visited[i]) dfsRecBranch(i);
}

int main(int argc, char const *argv[]) {
    ;
    return 0;
}