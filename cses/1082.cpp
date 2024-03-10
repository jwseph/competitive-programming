#include <bits/stdc++.h>
using namespace std;

#define ll long long

ll MOD = 1e9+7;

ll N;

int main() {
    cin >> N;
    ll res = 0;
    for (ll i = 1; i*i <= N; ++i) {
        ll a = (i+1)%MOD, b = N/i%MOD;
        res += (b-a+1)*(a+b)%MOD * 500000004%MOD;
        res += (N-i*i+i)/i*i;
        res %= MOD;
    }
    cout << res << endl;
}