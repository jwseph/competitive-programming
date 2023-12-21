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

int exp(int a, int b) {
    int res = 1;
    while (b) {
        if (b&1) res = (ll)res*a % MOD;
        a = (ll)a*a % MOD;
        b >>= 1;
    }
    return res;
}

int gcd(int a, int b) {
    return a%b == 0 ? b : gcd(b, a%b);
}

int lcm(int a, int b) {
    return a / gcd(a, b) * b;
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

ll fac[MAXX+1];
void factorial() {
    fac[0] = 1;
    for (int i = 1; i <= MAXX; ++i) fac[i] = fac[i-1] * i % MOD;
}

ll inv[MAXX+1];
void inverses() {
    inv[MAXX] = exp(fac[MAXX], MOD-2);
    for (int i = MAXX; i >= 1; --i) inv[i-1] = inv[i] * i % MOD;
}

int choose(int n, int k) {
    return fac[n] * inv[k] % MOD * inv[n-k] % MOD;
}