#include <bits/stdc++.h>
using namespace std;

struct Tree {
    typedef int T;
    static constexpr T def = INT_MAX;
    T f(T a, T b) { return min(a, b); }
    vector<T> t; int n;
    Tree(int n): t(2*n, def), n(n) {}
    void update(int i, T v) {
        for (t[i += n] = v; i /= 2;) t[i] = f(t[2*i], t[2*i+1]);
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

#define MAXN 200005

int N, NQ;

int main() {
    cin >> N >> NQ;
    Tree st(N);
    for (int i = 0; i < N; ++i) {
        int v; cin >> v;
        st.update(i, v);
    }
    while (NQ--) {
        int t; cin >> t;
        if (t == 1) {
            int i, v; cin >> i >> v; --i;
            st.update(i, v);
            continue;
        }
        int l, r; cin >> l >> r; --l;
        cout << st.query(l, r) << endl;
    }
}