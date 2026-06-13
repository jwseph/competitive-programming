#include <bits/stdc++.h>
using namespace std;

template<class T>
struct Tree {
    const T def{};
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

template<class T>
struct HeavyLight {  // usage: call all functions in order
    int N, timer = 0;
    vector<vector<int>> A;
    vector<int> P, D, sz, R, V;  // parent, depth, size, root, visit time
    Tree<T> tr;
    HeavyLight(int N): N(N), A(N), P(N), D(N), sz(N), V(N), tr(N) {
        for (int i = 0; i < N; ++i) R.push_back(i);
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
        if (k >= 0) R[k] = R[i];
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
        while (R[i] != R[j]) {
            if (D[R[i]] < D[R[j]]) swap(i, j);
            res = tr.f(res, tr.query(V[R[i]], V[i]+1));
            i = P[R[i]];
        }
        if (D[i] < D[j]) swap(i, j);
        res = tr.f(res, tr.query(V[j], V[i]+1));
        return res;
    }
};

struct Node {
    int cd = 1e9, len = 0;
    Node() {}
    Node(int cd): cd(cd), len(1) {}
    Node(int cd, int len): cd(cd), len(len) {}
    friend Node operator+(const Node& a, const Node& b) {
        return {
            min(a.cd, b.cd),
            a.len+b.len
        };
    }
};

const int N = 2e5+5;

int n, nq, a[N], v[N];
HeavyLight<Node> hl(N);

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin >> n >> nq;
    
    queue<int> q;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
        if (a[i]) {
            v[i] = 1;
            q.push(i);
        }
    }
    
    for (int e = 0; e < n-1; ++e) {
        int i, j; cin >> i >> j;
        hl.add(i, j);
    }
    hl.dfs_sz(1);
    hl.dfs_hl(1);

    for (int d = 0; q.size(); d++) {
        for (int qs = q.size(); qs --> 0;) {
            int i = q.front(); q.pop();
            hl.update(i, {d});
            for (int j: hl.A[i]) {
                if (v[j]) continue;
                v[j] = 1;
                q.push(j);
            }
        }
    }

    while (nq--) {
        int a, b; cin >> a >> b;
        Node path = hl.query(a, b);
        cout << path.cd*2 + path.len-1 << endl;
    }
}