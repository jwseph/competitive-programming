#include <bits/stdc++.h>
using namespace std;

template<class T>
struct Tree {
    static constexpr T def = INT_MAX;
    T f(T a, T b) { return min(a, b); }
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
vector<int> A[MAXN];
vector<int> E;
int V[MAXN];

void dfs(int i) {
    V[i] = E.size();
    E.push_back(i);
    for (int j: A[i]) {
        dfs(j);
        E.push_back(i);
    }
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin >> N >> M;
    for (int j = 2; j <= N; ++j) {
        int i; cin >> i;
        A[i].push_back(j);
    }
    dfs(1);
    Tree<int> T(E.size());
    for (int i = 0; i < E.size(); ++i) {
        T.update(i, E[i]);
    }
    while (M--) {
        int i, j; cin >> i >> j;
        int l = V[i], r = V[j];
        if (l > r) swap(l, r);
        cout << T.query(l, r+1) << endl;
    }
}