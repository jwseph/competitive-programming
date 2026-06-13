#include <bits/stdc++.h>
using namespace std;

using ll = long long;

const ll N = 1e12;
vector<ll> tri;

bool is1(ll x) {
    return binary_search(begin(tri), end(tri), x);
}

bool is2(ll x) {
    int r = tri.size()-1;
    for (int l = 0; l <= r; ++l) {
        while (l < r && tri[l]+tri[r] > x) --r;
        if (tri[l]+tri[r] == x) return true;
    }
    return false;
}

int main() {
    for (ll i = 1;; i++) {
        ll t = i*(i+1)/2;
        if (t > N) break;
        tri.push_back(t);
    }
    int nt; cin >> nt;
    while (nt--) {
        ll x; cin >> x;
        cout << (is1(x) ? 1 : is2(x) ? 2 : 3) << endl;
    }
}