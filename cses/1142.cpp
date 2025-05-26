#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int n;
ll a[200005];
stack<int> s;

int main() {
    cin >> n;
    s.push(0);
    ll res = 0;
    for (int i = 1; i <= n+1; ++i) {
        if (i <= n) cin >> a[i];
        int j = i;
        while (a[s.top()] > a[i]) {
            j = s.top();
            res = max(res, a[j]*(i-j));
            s.pop();
        }
        a[j] = a[i];
        s.push(j);
    }
    cout << res << endl;
}