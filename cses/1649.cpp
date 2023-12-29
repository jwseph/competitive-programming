#include <bits/stdc++.h>
using namespace std;

#define MAXN 200005

int N, NQ;

int T[2*MAXN];
void build() {
    for (int i = N-1; i >= 0; --i) T[i] = min(T[2*i], T[2*i+1]);
}
void modify(int i, int v) {
    T[i += N] = v;
    while (i /= 2) T[i] = min(T[2*i], T[2*i+1]);
}
int query(int l, int r) {
    int res = INT_MAX;
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
        int t; cin >> t;
        if (t == 1) {
            int i, v; cin >> i >> v; --i;
            modify(i, v);
            continue;
        }
        int l, r; cin >> l >> r; --l;
        cout << query(l, r) << endl;
    }
}