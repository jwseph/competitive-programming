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


using ll = long long;

struct Node {
    ll s = 0, ls = 0, rs = 0, ms = 0;
    Node() {}
    Node(int x): s(x), ls(max(0, x)), rs(ls), ms(ls) {}
    Node(ll s, ll ls, ll rs, ll ms): s(s), ls(ls), rs(rs), ms(ms) {}
    friend Node operator+(const Node& a, const Node& b) {
        return {
            a.s+b.s,
            max(a.ls, a.s+b.ls),
            max(b.rs, a.rs+b.s),
            max({a.ms, b.ms, a.rs+b.ls})
        };
    }
};

int n, nq;

int main() {
    cin >> n >> nq;
    Tree<Node> t(n);
    for (int i = 0; i < n; ++i) {
        int x; cin >> x;
        t.update(i, {x});
    }
    while (nq--) {
        int l, r; cin >> l >> r; --l;
        cout << t.query(l, r).ms << endl;
    }
}