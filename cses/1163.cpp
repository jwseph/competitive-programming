#include <bits/stdc++.h>
using namespace std;

using pii = pair<int, int>;

int X, N;
set<pii> S, B;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin >> X >> N;
    S.insert({X, 0});
    B.insert({X, 0});
    while (N--) {
        int p; cin >> p;
        auto it = S.lower_bound({p, 0});
        auto [r, l] = *it;
        S.erase(it);
        B.erase({r-l, l});
        S.insert({p, l});
        S.insert({r, p});
        B.insert({p-l, l});
        B.insert({r-p, p});
        cout << B.rbegin()->first << ' ';
    }
    cout << endl;
}