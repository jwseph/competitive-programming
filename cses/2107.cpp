#include <bits/stdc++.h>
using namespace std;

vector<int> prefix(string& s) {
    int n = s.size();
    vector<int> pi(n);
    for (int i = 1; i < n; ++i) {
        int j = pi[i-1];
        while (j && s[i] != s[j]) j = pi[j-1];
        j += s[i] == s[j];
        pi[i] = j;
    }
    return pi;
}

vector<int> zf(string& s) {
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

int main() {
    cin.tie(0)->sync_with_stdio(0);
    string s; cin >> s;
    for (int a: zf(s)) cout << a << ' ';
    cout << endl;
    for (int a: prefix(s)) cout << a << ' ';
    cout << endl;
}