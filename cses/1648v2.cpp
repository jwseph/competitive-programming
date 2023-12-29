#include <bits/stdc++.h>
using namespace std;

#define MAXN 200005
#define ll long long

int N, NQ, A[MAXN];

ll T[MAXN];
void update(int i, int v) {
    for (; i < N; i |= i+1) T[i] += v;
}
ll query(int i) {
    ll res = 0;
    for (; i; i &= i-1) res += T[i-1];
    return res;
}

int main() {
    cin >> N >> NQ;
    for (int i = 0; i < N; ++i) {
        cin >> A[i];
        update(i, A[i]);
    }
    while (NQ--) {
        int t; cin >> t;
        if (t == 1) {
            int i, v; cin >> i >> v; --i;
            v -= A[i];
            A[i] += v;
            update(i, v);
            continue;
        }
        int l, r; cin >> l >> r; --l;
        cout << query(r)-query(l) << endl;
    }
}