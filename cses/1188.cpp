#include <bits/stdc++.h>
using namespace std;

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
    int w, l, r, res;
    char lb, rb;
    Node(): w(0), l(0), r(0), res(0), lb(0), rb(0) {}
    Node(char c): w(1), l(1), r(1), res(1), lb(c), rb(c) {}
    Node(int w, int l, int r, int res, char lb, char rb): w(w), l(l), r(r), res(max(res, max(l, r))), lb(lb), rb(rb) {}
    friend Node operator+(const Node& a, const Node& b) {
        if (!a.w) return b;
        if (!b.w) return a;
        bool con = a.rb == b.lb;
        return {
            a.w + b.w,
            a.l + (con && a.l == a.w) * b.l,
            (con && b.r == b.w) * a.r + b.r,
            max({a.res, b.res, con * (a.r + b.l)}),
            a.lb,
            b.rb
        };
    }
};

int n, m;
string s;
Tree<Node> t(200005);

int main() {
    cin >> s; n = s.size();
    for (int i = 0; i < n; ++i) t.update(i, s[i]);
    cin >> m;
    while (m--) {
        int i; cin >> i; i--;
        s[i] = s[i] == '0' ? '1' : '0';
        t.update(i, s[i]);
        cout << t.query(0, n).res << ' ';
    }
    cout << endl;
}