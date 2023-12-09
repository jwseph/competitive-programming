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

#define MAXN 2003

int NT, N, K;
ll A[MAXN];

int main() {
    cin >> NT;
    while (NT--) {
        cin >> N >> K;
        for (int i = 0; i < N; ++i) {
            cin >> A[i];
        }
        if (K >= 3) {
            cout << 0 << endl;
            continue;
        }
        sort(A, A+N);
        ll res = A[0];
        for (int i = 0; i < N; ++i) {
            for (int j = i+1; j < N; ++j) {
                ll d = A[j]-A[i];
                res = min(res, d);
                if (K == 1) continue;
                int k = lower_bound(A, A+N, d) - A;
                res = min(res, A[k]-d);
                if (k > 0) res = min(res, d-A[k-1]);
            }
        }
        cout << res << endl;
    }
}