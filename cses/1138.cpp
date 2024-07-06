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
    void update(int l, int r, int v) {
        for (l += n, r += n; l < r; l /= 2, r /= 2) {
            if (l&1) t[l++] += v;
            if (r&1) t[--r] += v;
        }
    }
    T query(int i) {
        T res = 0;
        for (res += t[i += n]; i /= 2;) res += t[i];
        return res;
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
        T.update(G.tin[i], G.tout[i], A[i]);
    }
    while (M--) {
        int t, i; cin >> t >> i;
        if (t == 1) {
            int a; cin >> a;
            T.update(G.tin[i], G.tout[i], a-A[i]);
            A[i] = a;
            continue;
        }
        cout << T.query(G.tin[i]) << endl;
    }
}