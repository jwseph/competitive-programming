#include <bits/stdc++.h>
using namespace std;

#define ll long long

ll N, MOD = 1e9+7;

ll sol(ll p) {
    if (!p) return 1;
    if (p&1) return 2*sol(p-1) % MOD;
    ll r = sol(p/2);
    return r*r % MOD;
}

int main() {
    cin >> N;
    cout << sol(N) << endl;
}