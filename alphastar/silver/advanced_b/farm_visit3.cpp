#include <bits/stdc++.h>
using namespace std;

#define MOD 1000000007
#define ll long long
#define vr vector
#define pb push_back
#define all(v) (v).begin(), (v).end()

struct DSU {
    vector<int> p;
    DSU(int n) { p.assign(n, -1); }
    int size(int i) { return -p[find(i)]; }
    int find(int i) { return p[i] < 0 ? i : p[i] = find(p[i]); }
    bool unite(int i, int j) {
        i = find(i), j = find(j);
        if (i == j) return 0;
        if (p[i] > p[j]) swap(i, j);
        p[i] += p[j];
        p[j] = i;
        return 1;
    }
};

#define MAXN 100005

int N, M, G[MAXN], H[MAXN], anc[MAXN], lca[MAXN];
char C[MAXN];
string S;
vr<int> A[MAXN];
vr<pair<int, int>> Q[MAXN];
bool V[MAXN]{};
pair<int, int> query[MAXN];
DSU dsu(MAXN);

void dfs(int i, int g, int h) {
    V[i] = 1;
    anc[i] = i;
    ++(S[i] == 'G' ? g : h);
    G[i] = g;
    H[i] = h;
    for (int j: A[i]) {
        if (V[j]) continue;
        dfs(j, g, h);
        dsu.unite(i, j);
        anc[dsu.find(i)] = i;
    }
    for (auto [j, q]: Q[i]) {
        if (!V[j]) continue;
        lca[q] = anc[dsu.find(j)];
    }
}

int main() {
    cin >> N >> M >> S;
    for (int e = 0; e < N-1; ++e) {
        int i, j; cin >> i >> j; --i; --j;
        A[i].pb(j);
        A[j].pb(i);
    }
    for (int q = 0; q < M; ++q) {
        int i, j; char c; cin >> i >> j >> c; --i; --j;
        C[q] = c;
        Q[i].pb({j, q});
        Q[j].pb({i, q});
        query[q] = {i, j};
    }
    dfs(0, 0, 0);
    for (int q = 0; q < M; ++q) {
        auto [i, j] = query[q];
        int p = lca[q];
        int g = G[i]-G[p] + G[j]-G[p] + (S[p] == 'G');
        int h = H[i]-H[p] + H[j]-H[p] + (S[p] == 'H');
        cout << !!(C[q] == 'G' ? g : h);
    }
}