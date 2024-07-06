#include <bits/stdc++.h>
using namespace std;

using pii = array<int, 2>;

template<class T>
struct Tree {
    static constexpr T def = {INT_MAX, INT_MAX};
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

const int N = 3e5+5;
int n, k;
int pre[N];
string s;
Tree<pii> dp(N);

int main() {
    ifstream cin("redistricting.in");
    ofstream cout("redistricting.out");
    cin >> n >> k >> s;
    for (int i = 0; i < n; ++i) {
        pre[i+1] = pre[i] + (s[i] == 'G' ? 1 : -1);
    }
    dp.update(n, pii{0, pre[n]});
    for (int i = n-1; i >= 0; --i) {
        pii p = dp.query(i+1, min(i+k+1, n+1));
        dp.update(i, {p[0] + (p[1] >= pre[i]), pre[i]});
    }
    cout << dp.query(0, 1)[0] << endl;
}