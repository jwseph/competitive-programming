#include <bits/stdc++.h>
using namespace std;

struct Lift {
    int N, L, timer = 0;
    vector<vector<int>> A, P;
    vector<int> tin, tout;
    Lift(int N): N(N), A(N), tin(N), tout(N) {
        L = ceil(log2(N));
        P.resize(N, vector<int>(L+1));
    }
    void add(int i, int j) { A[i].push_back(j), A[j].push_back(i); }
    void dfs(int i, int p = -1) {
        tin[i] = timer++;
        P[i][0] = p >= 0 ? p : i;
        for (int k = 1; k <= L; ++k) {
            P[i][k] = P[P[i][k-1]][k-1];
        }
        for (int j: A[i]) {
            if (j == p) continue;
            dfs(j, i);
        }
        tout[i] = timer++;
    }
    bool is_ans(int a, int i) {
        return tin[a] <= tin[i] && tout[i] <= tout[a];
    }
    int lca(int i, int j) {
        if (is_ans(i, j)) return i;
        if (is_ans(j, i)) return j;
        for (int k = L; k >= 0; --k) {
            if (!is_ans(P[i][k], j)) i = P[i][k];
        }
        return P[i][0];
    }
};

template<class T>
struct Tree {
    static constexpr T def = 0;
    T f(T a, T b) { return a^b; }
    vector<T> t; int n;
    Tree(int n): t(2*n, def), n(n) {}
    void update(int l, int r, T v) {
        for (l += n, r += n; l < r; l /= 2, r /= 2) {
            if (l&1) t[l++] ^= v;
            if (r&1) t[--r] ^= v;
        }
    }
    T query(int i) {
        T res = def;
        for (res ^= t[i += n]; i /= 2;) res ^= t[i];
        return res;
    }
};

const int MAXN = 1e5+5;
int N, M;
int A[MAXN];
Lift G(MAXN);
Tree<int> T(2*MAXN);

void update(int i, int v) {
    T.update(G.tin[i], G.tout[i], v);
}

int query(int i, int j) {
    int a = G.lca(i, j);
    return T.query(G.tin[i]) ^ T.query(G.tin[j]) ^ A[a];
}

int main() {
    ifstream cin("cowland.in");
    ofstream cout("cowland.out");
    cin >> N >> M;
    for (int i = 0; i < N; ++i) cin >> A[i];
    for (int e = 0; e < N-1; ++e) {
        int i, j; cin >> i >> j; --i, --j;
        G.add(i, j);
    }
    G.dfs(0);
    for (int i = 0; i < N; ++i) {
        update(i, A[i]);
    }
    while (M--) {
        int t; cin >> t;
        if (t == 1) {
            int i, v; cin >> i >> v; --i;
            update(i, v^A[i]);
            A[i] = v;
            continue;
        }
        int i, j; cin >> i >> j; --i, --j;
        cout << query(i, j) << endl;
    }
}