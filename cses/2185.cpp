#include <bits/stdc++.h>
using namespace std;

using ll = long long;

const int N = 21;
int n;
ll k, pr[N];

int main() {
    cin >> k >> n;
    for (int i = 0; i < n; ++i) cin >> pr[i];
    ll res = 0;
    for (int s = 1; s < 1<<n; ++s) {
        ll p = 1, c = -1;
        for (int i = 0; i < n; ++i) {
            if (s&1<<i) {
                if (p > k/pr[i]) {
                    p = 1, c = 0;
                }
                p *= pr[i], c *= -1;
            }
        }
        res += c * k/p;
    }
    cout << res << endl;
}