#include <bits/stdc++.h>
using namespace std;

#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
using ll = long long;
using ld = long double;
using pll = pair<ll, ll>;

const int N = 1e6+6;
int t, n = 0;
pll st[N];

bool cmp(const pll& a, const pll& b) {
    return a.first*b.second < b.first*a.second;
}
ld eval(const pll& p) {
    return (ld)p.first/p.second;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin >> t;
    while (t--) {
        cin >> st[n].first;
        st[n].second = 1;
        n++;
        while (n >= 2 && cmp(st[n-1], st[n-2])) {
            st[n-2].first += st[n-1].first;
            st[n-2].second += st[n-1].second;
            n--;
        }
    }
    FOR(i, 0, n) {
        ld x = eval(st[i]);
        while (st[i].second--) cout << fixed << setprecision(9) << x << endl;
    }
}