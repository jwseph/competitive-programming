#include <bits/stdc++.h>
using namespace std;

using arr26 = array<int, 26>;
using ll = long long;

int main() {
    string s; cin >> s;

    bool v[26]{};
    for (char c: s) v[c-'a'] = 1;
    
    map<arr26, int> cp;
    arr26 p{};
    cp[p]++;
    ll res = 0;
    for (char c: s) {
        if (c == s[0]) {
            for (int i = 0; i < 26; ++i) {
                p[i] -= v[i];
            }
        }
        p[c-'a']++;
        res += cp[p]++;
    }
    cout << res << endl;
}