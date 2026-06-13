// maintain sorted idx[a[i]]
// for each adjacent l, r in idx, t[l] = r
// for query on l..r, check min (t on l..r) > r

#include <bits/stdc++.h>
using namespace std;

template<class T>
struct Tree {
    const T def = 2e9;
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

const int N = 2e5+5;

int n, nq, a[N];
map<int, set<int>> idx;
Tree<int> t(N);

void update(int i, int x) {
    // old
    auto& s0 = idx[a[i]];
    auto it = s0.lower_bound(i);
    if (it != s0.begin()) {
        auto l = it, r = it; --l; ++r;
        t.update(*l, r != s0.end() ? *r : 2e9);
    }
    s0.erase(it);

    // new
    a[i] = x;
    auto& s1 = idx[a[i]];
    it = s1.insert(i).first;
    if (it != s1.begin()) {
        auto l = it; --l;
        t.update(*l, i);
    }
    auto r = it; ++r;
    t.update(i, r != s1.end() ? *r : 2e9);
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin >> n >> nq;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        auto& s = idx[a[i]];
        if (s.size()) {
            t.update(*s.rbegin(), i);
        }
        s.insert(i);
    }
    while (nq--) {
        int qt, i, j; cin >> qt >> i >> j; --i;
        if (qt == 1) {
            update(i, j);
            continue;
        }
        --j;
        cout << (t.query(i, j+1) > j ? "YES" : "NO") << endl;
    }
}