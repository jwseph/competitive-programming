#include <bits/stdc++.h>
using namespace std;

#define MAXN 200005

int N, NQ;

int T[2*MAXN];
void build() {
    for (int i = N-1; i; --i) T[i] = min(T[i*2], T[i*2+1]);
}
void query(int l, int r) {
    int res = 0;
    for (l += N, r += N; l < r; l /= 2, r /= 2) {
        if (l&1) res = min(res, T[l++]);
        if (r&1) res = min(res, T[--r]);
    }
    return res;
}

int main() {
    cin >> N >> NQ;
    for (int i = 0; i < N; ++i) cin >> T[i+N];
    build();
    while (NQ--) {
        int l, r; cin >> l >> r; --l;
        cout << query(l, r) << endl;
    }
}