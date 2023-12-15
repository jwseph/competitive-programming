#include <bits/stdc++.h>
using namespace std;

#define MOD 1000000007
#define ll long long
#define vi vector<int>
#define si set<int>
#define ui unordered_set<int>
#define mii map<int, int>
#define uii unordered_map<int, int>
#define uivi unordered_map<int, vi>
#define pii pair<int, int>
#define tiii tuple<int, int, int>

int POW(int a, int b) {
    int res = 1;
    while (b) {
        if (b&1) res = (ll)res*a % MOD;
        a = (ll)a*a % MOD;
        b >>= 1;
    }
    return res;
}

int GCD(int a, int b) {
    return a%b == 0 ? b : GCD(b, a%b);
}

struct DSU {
    vector<int> parent, rank;
    DSU(int n) {
        rank.resize(n, 0);
        parent.resize(n);
        for (int i = 0; i < n; ++i) parent[i] = i;
    }
    int find(int u) {
        if (parent[u] == u) return u;
        return parent[u] = find(parent[u]);
    }
    void unite(int u, int v) {
        int U = find(u), V = find(v);
        if (U == V) return;
        if (rank[U] > rank[V]) swap(U, V);
        parent[U] = V;
        rank[U] += rank[U] == rank[V];
    }
};

#define MAXN 100005

int N, M;
string S;
DSU dsu(MAXN);

int main() {
    cin >> N >> M >> S;
    for (int e = 0; e < N-1; ++e) {
        int i, j; cin >> i >> j; --i; --j;
        if (S[i] == S[j]) dsu.unite(i, j);
    }
    while (M--) {
        int i, j; char t; cin >> i >> j >> t; --i; --j;
        cout << !(S[i] != t && dsu.find(i) == dsu.find(j));
    }
    cout << endl;
}