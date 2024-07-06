#include <bits/stdc++.h>
using namespace std;

struct Tree {
    typedef int T;
    static constexpr T def = 0;
    T f(T a, T b) { return a+b; }
    vector<T> t; int n, s;
    Tree(int n): t(2*n, def), n(n) {}
    Tree(vector<T> a) {
        s = a.size();
        n = 1;
        while (n < s) n <<= 1;
        t.resize(2*n, def);
        for (int i = 0; i < s; ++i) t[i+n] = a[i];
        for (int i = n-1; i; --i) t[i] = f(t[i*2], t[i*2+1]);
    }
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
    T lower_bound(int v) {
        if (t[1] <= v) return s;
        int i = 1, u = 0;
        while (i < n) {
            if (u+t[i*2] <= v) {
                u += t[i*2];
                i = i*2+1;
            } else {
                i = i*2;
            }
        }
        return i-n;
    }
};

const int MAXN = 2e5+5;
int N;
int A[MAXN];

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin >> N;
    for (int i = 0; i < N; ++i) cin >> A[i];
    vector<int> I(N, 1);
    Tree T(I);
    for (int i = 0; i < N+1; ++i) {
        for (int j = 0; j <= i; ++j) {
            T.query(j, i);
        }
    }
    while (N--) {
        int v; cin >> v; --v;
        int i = T.lower_bound(v);
        T.update(i, 0);
        cout << A[i] << ' ';
    }
    cout << endl;
}