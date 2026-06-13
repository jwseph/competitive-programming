#include <bits/stdc++.h>
using namespace std;

using ll = long long;

vector<ll> ones, tens;

ll g(int d, int w) {
    if (d == 1) return ones[w]+1;
    return tens[w] + d*ones[w];
}

ll f(ll h) {
    string s = to_string(h);
    int l = 0;
    ll res = 0;
    for (int i = 0; i < s.size(); ++i) {
        int d = s[i]-'0';
        if (d == 0) continue;
        int w = s.size()-i-1;
        res += g(d, w);
        res += l*d*tens[w];
        l += d == 1;
    }
    return res;
}

int main() {
    tens.push_back(1);
    ones.push_back(0);
    for (int i = 0; i < 18; ++i) {
        tens.push_back(tens.back()*10);
        ones.push_back((i+1)*tens[i]);
    }
    ll n; cin >> n;
    ll l = 0, r = 9e17;
    while (l < r) {
        ll h = (l+r+1)/2;
        if (f(h) > n) r = h-1;
        else l = h;
    }
    cout << l << endl;
}