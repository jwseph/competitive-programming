#include <bits/stdc++.h>
using namespace std;

#define MOD 1000000007
#define ll long long
#define pii pair<int, int>
#define tiii tuple<int, int, int>
#define t4i tuple<int, int, int, int>
#define t5i tuple<int, int, int, int, int>

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
bool res[MAXN]{};
string S;
map<pii, unordered_set<int>> M;
priority_queue<t5i, vector<t5i>, greater<>> A, B;

int main() {
    cin.tie(0); ios::sync_with_stdio(0);
    cin >> N >> Q >> S;
    X[0] = Y[0] = 0;
    for (int i = 0; i < N; ++i) {
        X[i+1] = X[i];
        Y[i+1] = Y[i];
        if (S[i] == 'U') ++Y[i+1];
        if (S[i] == 'D') --Y[i+1];
        if (S[i] == 'R') ++X[i+1];
        if (S[i] == 'L') --X[i+1];
    }
    for (int q = 0; q < Q; ++q) {
        int x, y, l, r; cin >> x >> y >> l >> r; --l;
        A.push({l, r, x, y, q});
        M[{x, y}].insert(q);
        if (X[l] == x && Y[l] == y || X[r] == x && Y[r] == y) res[q] = 1;
    }
    // P[0], P[1], P[l], P[l] + P[r]-P[r-1], P[l] + P[r]-P[r-2], ...
    // xy in P[0:l] or P[l]+P[r]-xy in P[l+1:r-1] or xy in P[r:n-1]
    for (int t = 0; t <= N; ++t) {
        while (A.size() && get<0>(A.top()) < t) {
            auto [l, r, x, y, q] = A.top();
            A.pop();
            M[{x, y}].erase(q);
            M[{X[l]+X[r]-x, Y[l]+Y[r]-y}].insert(q);
            B.push({r, l, x, y, q});
        }
        while (B.size() && get<0>(B.top()) < t) {
            auto [r, l, x, y, q] = B.top();
            B.pop();
            M[{X[l]+X[r]-x, Y[l]+Y[r]-y}].erase(q);
            M[{x, y}].insert(q);
            A.push({N+1, N+1, x, y, q});
        }
        for (int q: M[{X[t], Y[t]}]) {
            res[q] = 1;
        }
        M.erase({X[t], Y[t]});
    }
    for (int q = 0; q < Q; ++q) cout << (res[q] ? "YES" : "NO") << endl;
}