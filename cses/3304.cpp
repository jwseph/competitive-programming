#include <bits/stdc++.h>
using namespace std;

const int N = 1e5+5;
const int NQ = 2e5+5;

int n, nq, a[N], res[NQ];
vector<pair<int, int>> qs[N];

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin >> n >> nq;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
    }
    for (int q = 1; q <= nq; ++q) {
        int l, r; cin >> l >> r;
        qs[l].push_back({r, q});
    }
    a[n+1] = 2e9;
    vector<int> s = {n+1};
    for (int i = n; i >= 1; --i) {
        while (a[i] >= a[s.back()]) s.pop_back();
        s.push_back(i);
        for (auto [r, q]: qs[i]) {
            int p = lower_bound(begin(s), end(s), r, greater<int>()) - begin(s);
            res[q] = s.size()-p;
        }
    }
    for (int q = 1; q <= nq; ++q) {
        cout << res[q] << endl;
    }
}