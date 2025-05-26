#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;
using fr = pair<ll, ll>;

bool cmp(const fr& a, const fr& b) {
    return a.first*b.second < b.first*a.second;
}

int nt, n;

int main() {
    ifstream cin("subsonic_subway_input.txt");
    ofstream cout("out.txt");
    cin >> nt;
    for (int t = 1; t <= nt; ++t) {
        cin >> n;
        fr lo = {0, 1};
        fr hi = {1e9, 1};
        for (int i = 1; i <= n; ++i) {
            ll a, b; cin >> a >> b;
            hi = cmp(hi, fr{i, a}) ? hi : fr{i, a};
            lo = cmp(lo, fr{i, b}) ? fr{i, b} : lo;
        }
        cout << "Case #" << t << ": ";
        if (cmp(hi, lo)) {
            cout << -1 << endl;
        } else {
            cout << fixed << setprecision(6) << ((ld) lo.first / lo.second) << endl;
        }
    }
}