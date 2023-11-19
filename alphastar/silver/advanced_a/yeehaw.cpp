#include <bits/stdc++.h>
using namespace std;

#define ll long long

ll gen(int n, int i, int a, int b) {
    ll res = 0;
    while (n--) {
        res *= 10;
        res += i-- ? a : b;
    }
    return res;
}

ll X, Y;

int main() {
    cin >> X >> Y;
    int res = 0;
    for (int a = 0; a < 10; ++a) {
        for (int b = 0; b < 10; ++b) {
            if (a == b) continue;
            for (int n = 1; n <= 17; ++n) {
                for (int i = 0; i < n; ++i) {
                    if (a == 0 && i > 0) continue;
                    if (b == 0 && i == 0) continue;
                    ll cur = gen(n, i, a, b);
                    res += X <= cur && cur <= Y;
                }
            }
        }
    }
    cout << res << endl;
}