#include <bits/stdc++.h>
using namespace std;

struct DSU {
    vector<int> p;
    DSU(int n) { p.assign(n, -1); }
    int size(int i) { return -p[find(i)]; }
    int find(int i) { return p[i] < 0 ? i : p[i] = find(p[i]); }
    bool unite(int i, int j) {
        i = find(i), j = find(j);
        if (i == j) return 0;
        if (p[i] > p[j]) swap(i, j);
        p[i] += p[j];
        p[j] = i;
        return 1;
    }
};

#define MAXN 100005
#define MAXM 200005
#define ll long long
#define vr vector
#define pb push_back
#define all(v) (v).begin(), (v).end()

int N, M, F[MAXN];
set<pair<int, int>> S;
vector<int> A[MAXN], O;
bool V[MAXN]{};

int main() {
    cin >> N >> M;
    for (int e = 0; e < M; ++e) {
        int i, j; cin >> i >> j; --i; --j;
        A[i].pb(j); A[j].pb(i);
        ++F[i]; ++F[j];
    }
    for (int i = 0; i < N; ++i) {
        S.insert({F[i], i});
    }
    while (S.size()) {
        int i = S.begin()->second;
        V[i] = 1;
        S.erase(S.begin());
        O.pb(i);
        for (int j: A[i]) {
            if (V[j]) continue;
            S.erase({F[j], j});
            --F[j];
            S.insert({F[j], j});
        }
    }
    reverse(all(O));
    DSU dsu(N);
    ll res = 0;
    memset(V, 0, sizeof V);
    for (int i: O) {
        V[i] = 1;
        for (int j: A[i]) {
            if (!V[j]) continue;
            dsu.unite(i, j);
        }
        ll cur = (ll) F[i]*dsu.size(i);
        res = max(res, cur);
    }
    cout << res << endl;
}