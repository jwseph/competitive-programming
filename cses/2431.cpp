#include <bits/stdc++.h>
using namespace std;

#define ll long long

int N;

int sol(ll p) {
    --p;
    ll w = 9, n = 1;
    while (p >= n*w) {
        p -= n*w;
        w *= 10;
        n++;
    }
    p += w/9*n;
    return to_string(p/n)[p%n] - '0';
}

int main() {
    cin >> N;
    while (N--) {
        ll a; cin >> a;
        cout << sol(a) << endl;
    }
}