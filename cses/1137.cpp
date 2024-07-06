#include <bits/stdc++.h>
using namespace std;

using ll = long long;

struct Lift {
    int N, timer = 0;
    vector<vector<int>> A;
    vector<int> tin, tout;
    Lift(int N): N(N), A(N), tin(N), tout(N) {}
    void add(int i, int j) { A[i].push_back(j), A[j].push_back(i); }
    void dfs(int i, int p = -1) {
        tin[i] = timer++;
        for (int j: A[i]) {
            if (j == p) continue;
            dfs(j, i);
        }
        tout[i] = timer++;
    }
};

template<class T>
struct Tree {
    static constexpr T def{};
    T f(T a, T b) { return a+b; }
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

const int MAXN = 2e5+5;
int N, M;
int A[MAXN];
Lift G(MAXN);
Tree<ll> T(2*MAXN);

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin >> N >> M;
    for (int i = 1; i <= N; ++i) cin >> A[i];
    for (int e = 0; e < N-1; ++e) {
        int i, j; cin >> i >> j;
        G.add(i, j);
    }
    G.dfs(1);
    for (int i = 1; i <= N; ++i) {
        T.update(G.tin[i], A[i]);
    }
    while (M--) {
        int t, i; cin >> t >> i;
        if (t == 1) {
            int a; cin >> a;
            T.update(G.tin[i], a);
            continue;
        }
        cout << T.query(G.tin[i], G.tout[i]) << endl;
    }
}