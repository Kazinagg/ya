#include <iostream>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

struct Edge {
    int from, to, time, cost, index;
    bool operator < (const Edge& edge) const {
        return time < edge.time || (time == edge.time && cost < edge.cost);
    }
};

int findSet(int v, vector<int>& parent) {
    if (v == parent[v])
        return v;
    return parent[v] = findSet(parent[v], parent);
}

void unionSets(int a, int b, vector<int>& parent, vector<int>& rank) {
    a = findSet(a, parent);
    b = findSet(b, parent);
    if (a != b) {
        if (rank[a] < rank[b])
            swap(a, b);
        parent[b] = a;
        if (rank[a] == rank[b])
            ++rank[a];
    }
}

int main() {
    int N, M;
    cin >> N >> M;
    vector<Edge> edges;
    for (int i = 0; i < M; ++i) {
        int u, v, t;
        cin >> u >> v >> t;
        edges.push_back({u, v, t, 0, 0}); // Исходные ребра, стоимость и индекс не важны
    }

    int K;
    cin >> K;
    for (int i = 0; i < K; ++i) {
        int u, v, t, c;
        cin >> u >> v >> t >> c;
        edges.push_back({u, v, t, c, i + 1}); // Новые предложения
    }

  
    
    cout << "" << endl;

    return 0;
}
