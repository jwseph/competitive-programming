#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define vr vector
#define f first
#define s second

struct Tree {
    typedef pair<ll, pair<int, int>> T;
    static constexpr T def = {LLONG_MIN/4, {-1, -1}};
    T f(T a, T b) {
        T res = max(a, b);
        if (a.s.s == b.s.f) {
            T cur = {a.f+b.f, {a.s.f, b.s.s}};
            res = max(res, cur);
        }
        return res;
    }
    vr<T> t; int n;
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

int N, NQ;

int main() {
    cin >> N >> NQ;
    Tree T(N);
    for (int i = 0; i < N; ++i) {
        int v; cin >> v;
        T.update(i, {v, {i, i+1}});
    }
    while (NQ--) {
        int i, v; cin >> i >> v; --i;
        T.update(i, {v, {i, i+1}});
        cout << T.query(0, N).f << endl;
        if (NQ == 2) {
            cout << T.query(0, 3).f << endl;
        }
    }
}