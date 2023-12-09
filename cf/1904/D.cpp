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

#define MAXN 200005

int NT, N, A[MAXN], B[MAXN];
bool R[MAXN];
set<int> S;

bool sol() {
    S = {};
    for (int i = 0; i < N; ++i) {
        R[i] |= A[i] == B[i] || S.find(B[i]) != S.end();
        S.erase(begin(S), S.lower_bound(A[i]));
        S.erase(S.upper_bound(B[i]), end(S));
        S.insert(A[i]);
    }
    S = {};
    for (int i = N-1; i >= 0; --i) {
        R[i] |= A[i] == B[i] || S.find(B[i]) != S.end();
        S.erase(begin(S), S.lower_bound(A[i]));
        S.erase(S.upper_bound(B[i]), end(S));
        S.insert(A[i]);
    }
    for (int i = 0; i < N; ++i) {
        if (!R[i]) return 0;
    }
    return 1;
}

int main() {
    cin >> NT;
    while (NT--) {
        cin >> N;
        for (int i = 0; i < N; ++i) cin >> A[i];
        for (int i = 0; i < N; ++i) cin >> B[i];
        for (int i = 0; i < N; ++i) R[i] = 0;
        cout << (sol() ? "YES" : "NO") << endl;
    }
}