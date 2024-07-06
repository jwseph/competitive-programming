#include <bits/stdc++.h>
using namespace std;

using ll = long long;

template<class T>
struct Tree {
    T def;
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

struct Node {
    ll cur, sum;
    Node(ll cur, ll sum): cur(cur), sum(sum) {}
    Node(ll a = 0): cur(max(0ll, a)), sum(a) {}
    friend Node operator+(const Node& a, const Node& b) {
        return {max(a.cur, a.sum+b.cur), a.sum+b.sum};
    }
};

int N, M;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin >> N >> M;
    Tree<Node> T(N);
    for (int i = 0; i < N; ++i) {
        int a; cin >> a;
        T.update(i, Node(a));
    }
    for (int i = 0; i < N; ++i) {
        for (int j = i+1; j < N; ++j) {
            T.query(i, j);
        }
    }
    while (M--) {
        int t; cin >> t;
        if (t == 1) {
            int i, a; cin >> i >> a; --i;
            T.update(i, Node(a));
            continue;
        }
        int l, r; cin >> l >> r; --l;
        cout << T.query(l, r).cur << endl;
    }
}