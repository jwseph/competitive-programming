#include <bits/stdc++.h>
using namespace std;

using ll = long long;

const int MAXN = 2e5+5;
int N, A, B;

ll T[2*MAXN];
void build() {
    for (int i = N-1; i; --i) T[i] = min(T[i*2], T[i*2+1]);
}
ll query(int l, int r) {
    ll res = 1e18;
    for (l += N, r += N; l < r; l /= 2, r /= 2) {
        if (l&1) res = min(res, T[l++]);
        if (r&1) res = min(res, T[--r]);
    }
    return res;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin >> N >> A >> B;
    T[++N] = 0;
    for (int i = N+1; i < 2*N; ++i) {
        cin >> T[i];
        T[i] += T[i-1];
    }
    build();
    ll res = -1e18;
    for (int i = 1; i < N; ++i) {
        int r = max(0, i-A+1), l = max(0, i-B);
        res = max(res, T[i+N] - query(l, r));
    }
    cout << res << endl;
}