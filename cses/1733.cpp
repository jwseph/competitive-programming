#include <bits/stdc++.h>
using namespace std;

vector<int> zf(string s) {
    int n = s.size();
    vector<int> z(n);
    int x = 0, y = 0;
    for (int i = 1; i < n; i++) {
        z[i] = max(0, min(z[i-x], y-i+1));
        while (i+z[i] < n && s[z[i]] == s[i+z[i]]) {
            x = i; y = i+z[i]; z[i]++;
        }
    }
    return z;
}

int n;
string st;
vector<int> z;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin >> st;
    n = st.size();
    z = zf(st);
    for (int i = 1; i < n; ++i) {
        if (z[i] == n-i) cout << i << ' ';
    }
    cout << n << endl;
}