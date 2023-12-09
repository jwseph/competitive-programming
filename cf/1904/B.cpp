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

#define MAXN 100005

int NT, A[MAXN], N, R[MAXN];
ll P[MAXN];
pii PS[MAXN];
unordered_map<ll, int> dp;

int sol(ll val) {
    if (dp.find(val) != dp.end()) return val;
    int i = upper_bound(A, A+N, val) - A;
    if (P[i] == val) return i;
    return sol(P[i]);
}

int main() {
    cin >> NT;
    while (NT--) {
        dp = {};
        cin >> N;
        for (int i = 0; i < N; ++i) {
            cin >> A[i];
            PS[i] = {A[i], i};
        }
        sort(A, A+N);
        sort(PS, PS+N);
        P[0] = 0;
        for (int i = 0; i < N; ++i) {
            P[i+1] = P[i] + A[i];
        }
        for (int i = 0; i < N; ++i) {
            R[PS[i].second] = sol(P[i+1])-1;
        }
        for (int i = 0; i < N; ++i) cout << R[i] << ' ';
        cout << endl;
    }
}