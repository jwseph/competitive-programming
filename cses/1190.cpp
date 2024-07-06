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
    ll s = 0, l = 0, r = 0, cur = 0;
    Node() = default;
    Node(ll s, ll l, ll r, ll cur): s(s), l(l), r(r), cur(cur) {}
    Node(ll x): Node(x, max(0ll, x), max(0ll, x), max(0ll, x)) {}
    friend Node operator+(const Node& a, const Node& b) {
        return {a.s+b.s, max(a.l, a.s+b.l), max(b.r, a.r+b.s), max(max(a.cur, b.cur), a.r+b.l)};
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
    while (M--) {
        int i, a; cin >> i >> a; --i;
        T.update(i, Node(a));
        cout << T.query(0, N).cur << endl;
    }
}