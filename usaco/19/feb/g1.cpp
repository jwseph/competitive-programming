#include <bits/stdc++.h>
using namespace std;

template<class T>
struct Tree {
    static constexpr T def{};
    T f(T a, T b) { return a^b; }
    vector<T> t; int n;
    Tree(int n): t(2*n, def), n(n) {}
    void update(int i, T v) {
        for (t[i += n] = v; i /= 2;) t[i] = f(t[i*2], t[i*2+1]);
    }
    T query(int l, int r) {
        T al = def, ar = def;
        for (l += n, r += n; l < r; l /= 2, r /= 2) {
            if (l&1) al = f(al, t[l++]);
            if (r&1) ar = f(t[--r], ar);
        }
        return f(al, ar);
    }
};

template<class T>
struct HeavyLight {
    int N, timer = 0;
    vector<vector<int>> A;
    vector<int> P, D, sz, tp, V;
    Tree<T> tr;
    HeavyLight(int N): N(N), A(N), P(N), D(N), sz(N), V(N), tr(N) {
        for (int i = 0; i < N; ++i) tp.push_back(i);
    }
    void add(int i, int j) { A[i].push_back(j), A[j].push_back(i); }
    void dfs_sz(int i, int p = -1) {
        sz[i] = 1;
        for (int j: A[i]) {
            if (j == p) continue;
            P[j] = i, D[j] = D[i]+1;
            dfs_sz(j, i);
            sz[i] += sz[j];
        }
    }
    void dfs_hl(int i, int p = -1) {
        V[i] = timer++;
        int k = -1;
        for (int& j: A[i]) {
            if (j == p) continue;
            if (k < 0 || sz[k] < sz[j]) {
                k = j;
                swap(j, A[i][0]);
            }
        }
        if (k >= 0) tp[k] = tp[i];
        for (int j: A[i]) {
            if (j == p) continue;
            dfs_hl(j, i);
        }
    }
    void update(int i, int v) {
        tr.update(V[i], v);
    }
    T query(int i, int j) {
        T res = tr.def;
        while (tp[i] != tp[j]) {
            if (D[tp[i]] < D[tp[j]]) swap(i, j);
            res = tr.f(res, tr.query(V[tp[i]], V[i]+1));
            i = P[tp[i]];
        }
        if (D[i] < D[j]) swap(i, j);
        res = tr.f(res, tr.query(V[j], V[i]+1));
        return res;
    }
};

const int MAXN = 2e5+5;
int N, M;
int A[MAXN];

int main() {
    ifstream cin("cowland.in");
    ofstream cout("cowland.out");
    cin >> N >> M;
    for (int i = 0; i < N; ++i) cin >> A[i];
    HeavyLight<int> G(N);
    for (int e = 0; e < N-1; ++e) {
        int i, j; cin >> i >> j; --i, --j;
        G.add(i, j);
    }
    G.dfs_sz(0), G.dfs_hl(0);
    for (int i = 0; i < N; ++i) {
        G.update(i, A[i]);
    }
    while (M--) {
        int t; cin >> t;
        if (t == 1) {
            int i, v; cin >> i >> v; --i;
            G.update(i, v);
            continue;
        }
        int i, j; cin >> i >> j; --i, --j;
        cout << G.query(i, j) << endl;
    }
}