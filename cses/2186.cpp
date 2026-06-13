#include <bits/stdc++.h>
using namespace std;

using arr26 = array<int, 26>;
using ll = long long;

int n, cnt['z'+1];
string s;
map<arr26, int> cp;

int main() {
    cin >> s; n = s.size();

    for (char c: s) cnt[c]++;
    int k = 0, idx['z'+1];
    for (char c: s) {
        if (!cnt[c]) continue;
        cnt[c] = 0;
        idx[c] = k++;
    }
    
    ll res = 0;
    cp[arr26{}]++;
    for (char c: s) {
        cnt[idx[c]]++;
        arr26 p{};
        for (int i = 0; i < k; ++i) {
            p[i] = cnt[i] - cnt[0];
        }
        res += cp[p]++;
    }
    cout << res << endl;
}