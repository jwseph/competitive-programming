#include <bits/stdc++.h>
using namespace std;

using ll = long long;

struct BIT {
    vector<ll> t; int n;
    BIT(int n): t(n), n(n) {}
    void update(int i, int v) {
        for (; i < n; i |= i+1) t[i] += v;
    }
    ll query(int i) {
        ll res = 0;
        for (; i; i &= i-1) res += t[i-1];
        return res;
    }
    ll query(int l, int r) {
        return query(r) - query(l);
    }
};

const int MAXN = 2e5+5;
int N, M;
int A[MAXN];
map<int, int> V;
vector<array<int, 2>> Q[MAXN];
int res[MAXN];

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin >> N >> M;
    BIT T(N);
    for (int i = 0; i < N; ++i) cin >> A[i];
    for (int q = 0; q < M; ++q) {
        int l, r; cin >> l >> r; --l, --r;
        Q[r].push_back({l, q});
    }
    for (int i = 0; i < N; ++i) {
        T.update(i, 1);
        if (V[A[i]]) T.update(V[A[i]]-1, -1);
        V[A[i]] = i+1;
        for (auto [l, q]: Q[i]) {
            res[q] = T.query(l, i+1);
        }
    }
    for (int q = 0; q < M; ++q) cout << res[q] << endl;
}