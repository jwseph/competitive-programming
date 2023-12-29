#include <bits/stdc++.h>
using namespace std;

#define MAXN 200005
#define ll long long

int N, NQ;

ll T[2*MAXN]{};
void update(int l, int r, int v) {
    for (l += N, r += N; l < r; l /= 2, r /= 2) {
        if (l&1) T[l++] += v;
        if (r&1) T[--r] += v;
    }
}
ll query(int i) {
    ll res = T[i += N];
    while (i /= 2) res += T[i];
    return res;
}

int main() {
    cin >> N >> NQ;
    for (int i = 0; i < N; ++i) cin >> T[i+N];
    while (NQ--) {
        int t; cin >> t;
        if (t == 1) {
            int l, r, v; cin >> l >> r >> v; --l;
            update(l, r, v);
            continue;
        }
        int i; cin >> i; --i;
        cout << query(i) << endl;
    }
}