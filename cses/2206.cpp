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
    ll lp, rp, w;
    Node(): lp(INT_MAX), rp(INT_MAX), w(0) {}
    Node(ll lprice, ll rprice, ll width): lp(lprice), rp(rprice), w(width) {}
    Node(ll price): lp(price), rp(price), w(1) {}
    friend Node operator+(const Node& a, const Node& b) {
        return {min(a.lp, a.w+b.lp), min(b.rp, a.rp+b.w), a.w+b.w};
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
        int t, i; cin >> t >> i; --i;
        if (t == 1) {
            int a; cin >> a;
            T.update(i, Node(a));
            continue;
        }
        cout << min(T.query(i, N).lp, T.query(0, i+1).rp) << endl;
    }
}