#include <bits/stdc++.h>
using namespace std;

using ll = long long;

const int MAXN = 5e2+5;
int N, M;
map<int, ll> A[MAXN];
int V[MAXN], v = 1;

ll sol(int i, ll w, ll m) {
    if (i == N-1) return w;
    if (V[i] == v) return 0;
    V[i] = v;
    for (auto [j, w0]: A[i]) {
        if (w0 < m) continue;
        ll cut = sol(j, min(w, w0), m);
        if (cut) {
            A[i][j] -= cut;
            A[j][i] += cut;
            if (!A[i][j]) A[i].erase(j);
            return cut;
        }
    }
    return 0;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin >> N >> M;
    for (int e = 0; e < M; ++e) {
        int i, j, w; cin >> i >> j >> w; --i, --j;
        A[i][j] += w;
    }
    ll cur = 0, res = 0;
    for (ll m = INT_MAX; m; m /= 2) {
        ++v;
        while (cur = sol(0, LLONG_MAX, m)) {
            ++v;
            res += cur;
        }
    }
    cout << res << endl;
}