#include <bits/stdc++.h>
using namespace std;

#define ll long long

int NT;

ll sol(int r, int c) {
    ll g = max(r, c);
    ll i = (g+1)%2*g, j = g%2*g;
    return g*g + 1 + llabs(r-i) + llabs(c-j);
}

int main() {
    cin >> NT;
    while (NT--) {
        int r, c; cin >> r >> c; --r; --c;
        cout << sol(r, c) << endl;
    }
}