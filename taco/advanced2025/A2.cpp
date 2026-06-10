#include <bits/stdc++.h>
using namespace std;

const int N = 105;
int np, n, k;

int p[N], v[N];

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin >> np >> n >> k;
    for (int i = 0; i < n; ++i) {
        cin >> p[i] >> v[i];
    }
    int res = 0;
    for (int i = 0; i < n; ++i) {
        if (p[i] == 0 || p[i] == k) continue;
        if (v[i] == 1) {
            res = max(res, min(np-p[i], (k-p[i]+np)%np));
        } else {
            res = max(res, min(p[i], (p[i]-k+np)%np));
        }
    }
    cout << res << endl;
}