#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using t3i = array<int, 3>;

int k, n;
vector<t3i> hw;
map<int, int> dp[1003][202];

ll sol(int i, int p, int tmax) {

    tmax = min(tmax, 1000);
    if (i == n || tmax < hw[i][0]) return INT_MAX;
    
    if (dp[i][p].find(tmax) != dp[i][p].end()) {
        return dp[i][p][tmax];
    }

    // take or no take
    ll res = sol(i+1, p, tmax + hw[i][1]);
    if (p <= hw[i][2]) return hw[i][0];
    res = min(res, sol(i+1, p-hw[i][2], tmax));
    return dp[i][p][tmax] = res;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin >> k >> n;
    for (int i = 0; i < n; ++i) {
        int t, f, p; cin >> t >> f >> p;
        hw.push_back({t, f, p});
    }
    sort(hw.begin(), hw.end());
    ll res = sol(0, k, 10);
    if (res < INT_MAX) {
        cout << res << endl;
        return 0;
    }

    int tmax = 10;
    for (int i = 0; i < n; ++i) {
        if (tmax >= hw[i][0]) tmax += hw[i][1];
    }
    cout << tmax << endl;
}