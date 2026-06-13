#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const int mod = 1e9+7;

int n;
unordered_map<int, int> cnt;

int main() {
    cin >> n;
    for (int i = 0; i < n; ++i) {
        int x; cin >> x;
        cnt[x]++;
    }
    ll res = 1;
    for (const auto& [x, c]: cnt) {
        res *= c+1;
        res %= mod;
    }
    res -= 1;
    res += mod;
    res %= mod;
    cout << res << endl;
}