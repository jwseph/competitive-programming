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

int T, N, cnt[128]{};
string S;

int main() {
    cin >> T;
    while (T--) {
        cin >> N >> S;
        memset(cnt, 0, sizeof cnt);
        int res = 0;
        for (int i = 0; i < S.size(); ++i) {
            ++cnt[S[i]];
            if (i > 0) {
                char a = S[i], b = S[i-1];
                if (a != '1' || b != '1') res = 1;
            }
        }
        res |= cnt['0'] > cnt['1'];
        cout << (res ? "YES" : "NO") << endl;
    }
}