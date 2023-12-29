#include <bits/stdc++.h>
using namespace std;

#define MN 200005
#define pii pair<int, int>
#define ll long long
#define vr vector
#define pb push_back
#define all(v) (v).begin(), (v).end()

int NT, N, T[2*MN];

void update(int i, int v) {
    for (T[i += N] = v; i /= 2;) T[i] = T[i*2] + T[i*2+1];
}
int query(int l, int r) {
    int res = 0;
    for (l += N, r += N; l < r; l /= 2, r /= 2) {
        if (l&1) res += T[l++];
        if (r&1) res += T[--r];
    }
    return res;
}

int main() {
    cin >> NT;
    while (NT--) {
        cin >> N;
        vr<pii> A;
        for (int i = 0; i < N; ++i) {
            int a; cin >> a;
            A.pb({a, i});
            update(i, 0);
        }
        sort(all(A));
        ll res = 0;
        for (auto [a, i]: A) {
            res += query(i+1, N);
            update(i, 1);
        }
        cout << res << endl;
    }
}