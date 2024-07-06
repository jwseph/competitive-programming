#include <bits/stdc++.h>
using namespace std;

using ll = long long;

template<class T>
struct Sqrt {
    int n, w;
    vector<T> a, b;
    Sqrt(int n, int k): n(n), w((n+k-1)/k), a(n), b(k) {}
    void update(int i, T v) {
        b[i/w] += v-a[i];
        a[i] = v;
    }
    T query(int l, int r) {
        T res = 0;
        for (int i = l; i < r;) {
            if (i%w == 0 && i+w <= r) {
                res += b[i/w], i += w;
                continue;
            }
            res += a[i++];
        }
        return res;
    }
};

const int MAXN = 2e5+5;
int N, M;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin >> N >> M;
    Sqrt<ll> sq(N, ceil(sqrt(N)));
    for (int i = 0; i < N; ++i) {
        int a; cin >> a;
        sq.update(i, a);
    }
    while (M--) {
        int t; cin >> t;
        if (t == 1) {
            int i, a; cin >> i >> a; --i;
            sq.update(i, a);
            continue;
        }
        int l, r; cin >> l >> r; --l;
        cout << sq.query(l, r) << endl;
    }
}