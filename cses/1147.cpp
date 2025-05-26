#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int nr, n;
ll p[1003], a[1003];
stack<int> s;

int main() {
    cin >> nr >> n;
    ll res = 0;
    for (int r = 0; r < nr; ++r) {
        string str; cin >> str;
        for (int i = 1; i <= n; ++i) {
            p[i]++;
            if (str[i-1] == '*') p[i] = 0;
            a[i] = p[i];
        }
        s = {};
        s.push(0);
        for (int i = 1; i <= n+1; ++i) {
            int j = i;
            while (a[s.top()] > a[i]) {
                j = s.top();
                res = max(res, a[j]*(i-j));
                s.pop();
            }
            a[j] = a[i];
            s.push(j);
        }
    }
    cout << res << endl;
}