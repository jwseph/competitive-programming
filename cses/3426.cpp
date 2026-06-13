#include <bits/stdc++.h>
using namespace std;
 
using ll = long long;
 
int n, k, x, a, b, c;
 
int main() {
    cin >> n >> k;
    cin >> x >> a >> b >> c;
    ll y = x, z = x;
    ll res = 0, cur = 0;
    for (int i = 0; i < n; ++i) {
        // insert
        cur ^= y;
        y = (y*a+b) % c;
        if (i-k >= 0) {
            // erase
            cur ^= z;
            z = (z*a+b) % c;
        }
        if (i >= k-1) {
            // print
            res ^= cur;
        }
    }
    cout << res << endl;
}