#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const int MAXN = 2e5+5;

int N, K, A[MAXN];

ll sol(ll t) {
    ll res = 0;
    for (int i = 0; i < N && res < K; ++i) {
        res += t/A[i];
    }
    return res;
}

int main() {
    cin >> N >> K;
    for (int i = 0; i < N; ++i) cin >> A[i];
    ll l = 0, r = 1e18;
    while (l < r) {
        ll h = (l+r)/2ll;
        if (K <= sol(h)) r = h;
        else l = h+1;
    }
    cout << l << endl;
}