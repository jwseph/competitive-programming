#include <bits/stdc++.h>
using namespace std;

int N, Q;
set<pair<int, int>> S;

int main() {
    cin >> N >> Q;
    for (int i = 0; i < N; ++i) {
        int t; cin >> t;
        S.insert({t, i});
    }
    while (Q--) {
        int a; cin >> a;
        auto it = S.upper_bound({a, INT_MAX});
        if (it == S.begin()) {
            cout << -1 << endl;
            continue;
        }
        --it;
        cout << it->first << endl;
        S.erase(it);
    }
}