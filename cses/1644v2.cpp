#include <bits/stdc++.h>
using namespace std;

using ll = long long;

struct Tree {
    using T = ll;
    static constexpr T def = 1e18;
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

const int MAXN = 2e5+5;
int N, A, B;
ll P[MAXN];

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin >> N >> A >> B;
    Tree T(N+1);
    P[0] = 0;
    T.update(0, P[0]);
    for (int i = 1; i <= N; ++i) {
        cin >> P[i];
        P[i] += P[i-1];
        T.update(i, P[i]);
    }
    ll res = -1e18;
    for (int i = 1; i <= N; ++i) {
        int r = max(0, i-A+1), l = max(0, i-B);
        res = max(res, P[i] - T.query(l, r));
    }
    cout << res << endl;
}