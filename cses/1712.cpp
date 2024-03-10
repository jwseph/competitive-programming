#include <bits/stdc++.h>
using namespace std;

#define ll long long

ll MOD = 1e9+7;

ll exp(ll a, ll b, ll p) {
    if (b == 0) return 1;
    if (b&1) return exp(a, b-1, p) * a % p;
    ll res = exp(a, b/2, p);
    return res * res % p;
}

int N;

int main() {
    cin >> N;
    while (N--) {
        int a, b, c; cin >> a >> b >> c;
        cout << exp(a, exp(b, c, MOD-1), MOD) << endl;
    }
}