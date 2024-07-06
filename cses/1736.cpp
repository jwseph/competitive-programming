#include <bits/stdc++.h>
using namespace std;

using ll = long long;

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

struct Node {
    ll x = 0, v = 0, a = 0, t = 0;
    Node() = default;
    Node(ll x): x(x), t(1) {}
    Node(ll x, ll v, ll a, ll t): x(x), v(v), a(a), t(t) {}
    friend Node operator+(const Node& p, const Node& q) {
        return {q.x+p.x + p.v*q.t + q.t*(q.t+1)/2*p.a, q.v+p.v + p.a*q.t , q.a+p.a, q.t+p.t};
    }
};

int N, M;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin >> N >> M;
    Tree<Node> T(N+1);
    for (int i = 0; i < N; ++i) {
        int x; cin >> x;
        T.update(i, Node(x));
    }
    while (M--) {
        int t, l, r; cin >> t >> l >> r; --l;
        if (t == 1) {
            T.update(l, Node(0, 0, 1, 0) + T.query(l, l+1));
            T.update(r, Node(0, l-r, -1, 0) + T.query(r, r+1));
            continue;
        }
        ll cur = T.query(0, r).x - T.query(0, l).x;
        cout << cur << endl;
    }
}