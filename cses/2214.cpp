#include <bits/stdc++.h>
using namespace std;

using ll = long long;

void sol(ll n, ll k) {
    if (k >= n-1) {
        cout << n << ' ';
        if (n-1) sol(n-1, k-n+1);
        return;
    }
    for (int i = 1; i < n-k; ++i) {
        cout << i << ' ';
    }
    cout << n << ' ';
    for (int i = n-k; i < n; ++i) {
        cout << i << ' ';
    }
}

int main() {
    ll n, k; cin >> n >> k;
    sol(n, k);
}