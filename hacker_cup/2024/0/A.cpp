#include <bits/stdc++.h>
using namespace std;

using ll = long long;

ll tn, n, k;
ll a[1003];

bool sol() {
    cin >> n >> k;
    for (int i = 0; i < n; ++i) cin >> a[i];
    sort(a, a+n);
    if (n == 1) return a[0] <= k;
    for (int i = 0; i < n-1; ++i) {
        k -= min(a[i], a[0]*2);
    }
    return k >= 0;
}

int main() {
    ofstream cout("out.txt");
    cin >> tn;
    for (int ti = 1; ti <= tn; ++ti) {
        cout << "Case #" << ti << ": " << (sol() ? "YES" : "NO") << endl;
    }
}