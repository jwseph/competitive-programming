#include <bits/stdc++.h>
using namespace std;

#define MAXN 41
#define ll long long

int N, K, A[MAXN];

vector<ll> sol(int l, int r) {
    vector<ll> res;
    for (int s = 0; s < (1<<r-l); ++s) {
        ll cur = 0;
        for (int i = l; i < r; ++i) {
            if (s&1<<i-l) cur += A[i];
        }
        res.push_back(cur);
    }
    sort(begin(res), end(res));
    return res;
}

int main() {
    cin >> N >> K;
    for (int i = 0; i < N; ++i) cin >> A[i];
    auto L = sol(0, N/2), R = sol(N/2, N);
    ll res = 0;
    for (ll s: L) {
        auto r = upper_bound(begin(R), end(R), K-s);
        auto l = lower_bound(begin(R), end(R), K-s);
        res += r-l;
    }
    cout << res << endl;
}