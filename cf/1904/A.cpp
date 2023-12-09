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

int NT, R1, C1, R2, C2, D1, D2;
int d1r[8] = {-1, -1, 0, 0, 1, 1, 0, 0};
int d2r[8] = {0, 0, -1, 1, 0, 0, 1, -1};
int d1c[8] = {0, 0, 1, 1, 0, 0, -1, -1};
int d2c[8] = {-1, 1, 0, 0, 1, -1, 0, 0};

int main() {
    cin >> NT;
    while (NT--) {
        cin >> D1 >> D2 >> R1 >> C1 >> R2 >> C2;
        map<pii, int> vst;
        for (int d = 0; d < 8; ++d) {
            int r = R1 + d1r[d]*D1 + d2r[d]*D2;
            int c = C1 + d1c[d]*D1 + d2c[d]*D2;
            vst[{r, c}] = 0;
        }
        int res = 0;
        for (int d = 0; d < 8; ++d) {
            int r = R2 + d1r[d]*D1 + d2r[d]*D2;
            int c = C2 + d1c[d]*D1 + d2c[d]*D2;
            if (vst.find({r, c}) != vst.end() && vst[{r, c}] == 0) {
                vst[{r, c}] = 1;
                ++res;
            }
        }
        cout << res << endl;
    }
}