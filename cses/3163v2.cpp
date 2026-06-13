#include <bits/stdc++.h>
using namespace std;

using Node = vector<int>;
Node operator+(const Node& a, const Node& b) {
    vector<int> res;
    merge(begin(a), end(a), begin(b), end(b), back_inserter(res));
    return res;
}

template<class T>
struct Tree {
    const T def{};
    T f(T a, T b) { return a+b; }
    vector<T> t; int n;
    Tree(int n): t(2*n, def), n(n) {}
    Tree(const vector<T>& a): Tree(a.size()) {
        for (int i = 0; i < n; ++i) t[i+n] = a[i];
        for (int i = n-1; i > 0; --i) {
            T &a = t[i*2], &b = t[i*2+1];
            merge(begin(a), end(a), begin(b), end(b), back_inserter(t[i]));
        }
    }
    int query_count(int l, int r, int a, int b) {
        int res = 0;
        for (l += n, r += n; l < r; l /= 2, r /= 2) {
            if (l&1) {
                res += (
                    upper_bound(begin(t[l]), end(t[l]), b)
                    - lower_bound(begin(t[l]), end(t[l]), a)
                );
                l++;
            }
            if (r&1) {
                --r;
                res += (
                    upper_bound(begin(t[r]), end(t[r]), b)
                    - lower_bound(begin(t[r]), end(t[r]), a)
                );
            }
        }
        return res;
    }
};

int n, nq;

int main() {
    cin >> n >> nq;
    vector<Node> v(n);
    for (int i = 0; i < n; ++i) {
        int x; cin >> x;
        v[i].push_back(x);
    }
    Tree<Node> t(v);
    while (nq--) {
        int l, r, a, b; cin >> l >> r >> a >> b; --l;
        cout << t.query_count(l, r, a, b) << endl;
    }
}