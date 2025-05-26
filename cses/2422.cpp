#include <bits/stdc++.h>
using namespace std;

using ll = long long;

ll n;

ll count_before_including(ll v) {
    ll res = 0;
    for (ll i = 1; i <= n; ++i) {
        res += min(v/i, n);
    }
    return res;
}

int main() {
    cin >> n;
    ll l = 0, r = n*n;
    while (l < r) {
        ll h = (l+r)/2;
        if (count_before_including(h) >= (n*n+1)/2) r = h;
        else l = h+1;
    }
    cout << l << endl;
}