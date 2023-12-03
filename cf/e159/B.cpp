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

int NT;
ll N, P, L, T;

ll soltasks(ll d) {
    return min(d*2, (N+6)/7);
}

bool sol(ll d, ll p, ll l, ll t) {
    return d*l + soltasks(d)*t >= p;
}

int bs() {
    int l = 0, r = N;
    while (l < r) {
        int h = (l+r)/2;
        if (sol(h, P, L, T)) r = h;
        else l = h+1;
    }
    return l;
}

int main() {
    cin >> NT;
    while (NT--) {
        cin >> N >> P >> L >> T;
        cout << N-bs() << endl;
    }
}