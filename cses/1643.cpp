#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int N;

int main() {
    cin >> N;
    ll res = LLONG_MIN, cur = 0;
    while (N--) {
        ll a; cin >> a;
        cur = max(cur+a, a);
        res = max(res, cur);
    }
    cout << res << endl;
}