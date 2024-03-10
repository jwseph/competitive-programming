#include <bits/stdc++.h>
using namespace std;

#define ll long long

ll MOD = 1e9+7;

ll exp(ll a, ll b) {
    if (b == 0) return 1;
    if (b&1) return exp(a, b-1) * a % MOD;
    ll res = exp(a, b/2);
    return res * res % MOD;
}

int N;

int main() {
    cin >> N;
    while (N--) {
        int a, b; cin >> a >> b;
        cout << exp(a, b) << endl;
    }
}