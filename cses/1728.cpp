#include <bits/stdc++.h>
using namespace std;

using ld = __float128;

const int K = 102;
int n;
ld pb[K];

int main() {
    cin >> n;
    ld res = 0;
    while (n--) {
        double a; cin >> a;
        for (int k = 1; k <= a; ++k) {
            res += pb[k]/a;
            pb[k] += (a-k)/a;
        }
    }
    cout << fixed << setprecision(6) << double(res) << endl;
}