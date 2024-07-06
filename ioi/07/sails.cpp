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
    ll wait = 0, open = 0, used = 0;
    Node() = default;
    Node(ll wait): Node(wait, 0) {}
    Node(ll wait, ll open): wait(wait), open(open) {}
    Node(ll wait, ll open, ll used): wait(wait), open(open), used(used) {}
    friend Node operator+(const Node& a, const Node& b) {
        ll take = min(b.wait, a.open);
        return {a.wait+b.wait-take, a.open+b.open-take, a.used+b.used+take};
    }
};

const int MAXN = 1e5+5;
int N, M = 0;
int H[MAXN], S[MAXN];

int sol(int cap) {
    Tree<Node> T(M);
    for (int h = 0; h < M; ++h) {
        T.update(h, Node(0, cap));
    }
    for (int i = 0; i < N; ++i) {
        int h = H[i], s = S[i];
        T.update(h-1, T.t[h-1+M] + Node(s));
    }
    if (T.query(0, M).wait) return -1;
    ll res = 0;
    for (int i = 0; i < M; ++i) for (int j = i+1; j <= M; ++j) {
        auto cur = T.query(i, j);
        cout << "[i=" << i << ",j=" << j << ",w=" << cur.wait << ",o=" << cur.open << ",u=" << cur.used << "]\n";
    }
    cout << endl;

    for (int i = 0; i < M; ++i) {
        ll cur = T.query(i, M).used - T.query(i+1, M).used;
        res += cur*(cur-1)/2;
    }
    return res;
}

int main() {
    cin >> N;
    ll l = 0, r = 0;
    for (int i = 0; i < N; ++i) {
        cin >> H[i] >> S[i];
        r += S[i];
        M = max(M, H[i]);
    }
    for (int i = 1; i <= r; ++i) {
        cout << "solving i=" << i << " res=" << sol(i) << endl;
    }
    // while (l < r) {
    //     ll h = (l+r)/2;
    //     if (sol(h) >= 0) r = h;
    //     else l = h+1;
    // }
    // cout << sol(l) << endl;
}