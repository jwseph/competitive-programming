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

#define MAXN 200'000

int T, N, A[MAXN];

int main() {
    cin >> T;
    while (T--) {
        cin >> N;
        for (int i = 0; i < N; ++i) cin >> A[i];
        if (N == 1) {
            cout << 1 << endl;
            continue;
        }
        sort(A, A+N);
        ll cur = 0;
        for (int i = 0; i < N-1; ++i) {
            int d = A[N-1]-A[i];
            if (cur == 0) {
                cur = d;
                continue;
            }
            cur = GCD(cur, d);
        }
        int ext = N;
        int t;
        for (t = 1; binary_search(A, A+N, A[N-1]-t*cur); ++t);
        ext = min(ext, t);
        ll res = ext;
        for (int i = 0; i < N; ++i) res += (A[N-1]-A[i])/cur;
        cout << res << endl;
    }
}