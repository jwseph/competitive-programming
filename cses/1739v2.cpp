#include <bits/stdc++.h>
using namespace std;

#define MAXN 1003
#define ll long long

int N, NQ;
bool A[MAXN][MAXN];

int T[MAXN][MAXN]{};
void update(int r, int c, int v) {
    for (int i = r; i < N; i |= i+1) {
        for (int j = c; j < N; j |= j+1) T[i][j] += v;
    }
}
ll query(int r, int c) {
    ll res = 0;
    for (int i = r; i; i &= i-1) {
        for (int j = c; j; j &= j-1) res += T[i-1][j-1];
    }
    return res;
}

int main() {
    cin >> N >> NQ;
    for (int r = 0; r < N; ++r) {
        for (int c = 0; c < N; ++c) {
            char a; cin >> a;
            A[r][c] = a == '*';
            update(r, c, A[r][c]);
        }
    }
    while (NQ--) {
        int t; cin >> t;
        if (t == 1) {
            int r, c; cin >> r >> c; --r; --c;
            int v = A[r][c] ? -1 : 1;
            A[r][c] += v;
            update(r, c, v);
            continue;
        }
        int r, c, R, C; cin >> r >> c >> R >> C; --r; --c;
        ll res = query(R, C) - query(R, c) - query(r, C) + query(r, c);
        cout << res << endl;
    }
}