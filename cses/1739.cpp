#include <bits/stdc++.h>
using namespace std;

#define ll long long

template<int...>
struct BIT {
    int v = 0;
    void update(int v) { this->v += v; }
    ll query() { return v; }
};

template<int N, int... Ns>
struct BIT<N, Ns...> {
    BIT<Ns...> bit[N];
    template<typename... Ts>
    void update(int i, Ts... args) {
        for (; i < N; i |= i+1) bit[i].update(args...);
    }
    template<typename... Ts>
    ll query(int l, int r, Ts... args) {
        ll res = 0;
        for (; r; r &= r-1) res += bit[r-1].query(args...);
        for (; l; l &= l-1) res -= bit[l-1].query(args...);
        return res;
    }
};

#define MAXN 1003

int N, NQ;
bool A[MAXN][MAXN];
BIT<MAXN, MAXN> bit;

int main() {
    cin >> N >> NQ;
    for (int r = 0; r < N; ++r) {
        for (int c = 0; c < N; ++c) {
            char a; cin >> a;
            A[r][c] = a == '*';
            bit.update(r, c, A[r][c]);
        }
    }
    while (NQ--) {
        int t; cin >> t;
        if (t == 1) {
            int r, c; cin >> r >> c; --r; --c;
            int v = A[r][c] ? -1 : 1;
            A[r][c] += v;
            bit.update(r, c, v);
            continue;
        }
        int r, c, R, C; cin >> r >> c >> R >> C; --r; --c;
        cout << bit.query(r, R, c, C) << endl;
    }
}