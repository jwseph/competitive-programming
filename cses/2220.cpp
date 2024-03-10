#include <bits/stdc++.h>
using namespace std;

using ll = long long;

string S;

ll sol(int i, bool l, int p, bool z) {
    if (i == S.size()) return 1;
    if (!l) {
        ll res = 9*sol(i+1, l, 0, 0);
        if (z) res += sol(i+1, l, 0, z);
        return res;
    }
    ll res = 0;
    for (int d = 0; d < 10; ++d) {
        if (d == p) continue;
        if (l && d > S[i]-'0') continue;
        bool zz = z && d == 0;
        res += sol(i+1, d == S[i]-'0', d, zz);
    }
    return res;
}
ll sol(ll n) {
    S = to_string(n);
    return sol(0, 1, -1, 1);
}

int main() {
    ll a, b; cin >> a >> b;
    cout << sol(b) - sol(a-1) << endl;
}
