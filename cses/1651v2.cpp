#include <bits/stdc++.h>
using namespace std;

#define MAXN 200005
#define ll long long

int N, NQ;

ll T[MAXN]{};
void update(int i, int v) {
    for (; i; i &= i-1) T[i-1] += v;
}
ll query(int i) {
    ll res = 0;
    for (; i < N; i |= i+1) res += T[i];
    return res;
}

int main() {
    cin >> N >> NQ;
    for (int i = 0; i < N; ++i) {
        int v; cin >> v;
        update(i+1, v);
        update(i, -v);
    }
    while (NQ--) {
        int t; cin >> t;
        if (t == 1) {
            int l, r, v; cin >> l >> r >> v; --l;
            update(r, v);
            update(l, -v);
            continue;
        }
        int i; cin >> i; --i;
        cout << query(i) << endl;
    }
}