#include <bits/stdc++.h>
using namespace std;

#define MOD 1000000007
#define ll long long
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

#define MAXN 200'001

int N, Q, X[MAXN], Y[MAXN];
string S;
map<pii, vector<int>> T;

bool sol(int x, int y, int l, int r) {
    vector<int>& V = T[{x, y}];
    if (V.size() && V[0] <= l) return 1;
    if (lower_bound(begin(V), end(V), r) != end(V)) return 1;
    vector<int>& V2 = T[{X[l]+X[r]-x, Y[l]+Y[r]-y}];
    auto it = lower_bound(begin(V2), end(V2), l);
    return it != end(V2) && *it <= r;
}

int main() {
    // P[0], P[1], P[l], P[l] + P[r]-P[r-1], P[l] + P[r]-P[r-2], ...
    // xy in P[0:l] or P[l]+P[r]-xy in P[l+1:r-1] or xy in P[r:n-1]
    cin >> N >> Q >> S;
    X[0] = Y[0] = 0;
    T[{0, 0}].push_back(0);
    for (int i = 0; i < N; ++i) {
        X[i+1] = X[i];
        Y[i+1] = Y[i];
        if (S[i] == 'U') ++Y[i+1];
        if (S[i] == 'D') --Y[i+1];
        if (S[i] == 'R') ++X[i+1];
        if (S[i] == 'L') --X[i+1];
        T[{X[i+1], Y[i+1]}].push_back(i+1);
    }
    while (Q--) {
        int x, y, l, r; cin >> x >> y >> l >> r; --l;
        cout << (sol(x, y, l, r) ? "YES" : "NO") << endl;
    }
}