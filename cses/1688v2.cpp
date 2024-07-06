#include <bits/stdc++.h>
using namespace std;

struct DSU {
    vector<int> p;
    DSU(int n) { p.assign(n, -1); }
    int size(int i) { return -p[find(i)]; }
    int find(int i) { return p[i] < 0 ? i : p[i] = find(p[i]); }
    int unite(int i, int j) {
        i = find(i), j = find(j);
        if (i == j) return i;
        if (p[i] > p[j]) swap(i, j);
        p[i] += p[j];
        p[j] = i;
        return i;
    }
};

const int MAXN = 2e5+5;
int N, M;
vector<int> A[MAXN];
vector<pair<int, int>> Q[MAXN];
bool V[MAXN];
DSU dsu(MAXN);
int P[MAXN], R[MAXN];

void dfs(int i) {
    V[i] = 1;
    P[dsu.find(i)] = i;
    for (int j: A[i]) {
        dfs(j);
        P[dsu.unite(i, j)] = i;
    }
    for (auto [j, q]: Q[i]) {
        if (!V[j]) continue;
        R[q] = P[dsu.find(j)];
    }
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin >> N >> M;
    for (int j = 2; j <= N; ++j) {
        int i; cin >> i;
        A[i].push_back(j);
    }
    for (int q = 0; q < M; ++q) {
        int i, j; cin >> i >> j;
        Q[i].push_back({j, q});
        Q[j].push_back({i, q});
    }
    dfs(1);
    for (int q = 0; q < M; ++q) {
        cout << R[q] << endl;
    }
}