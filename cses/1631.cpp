#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int N;

int main() {
    cin >> N;
    ll t = 0, m = 0;
    while (N--) {
        ll a; cin >> a;
        t += a;
        m = max(m, a);
    }
    cout << max(t, 2*m) << endl;
}