#include <bits/stdc++.h>
using namespace std;

const int MAXK = 1e5+1;
int N;
bitset<MAXK> dp;

int main() {
    cin >> N;
    dp[0] = 1;
    while (N--) {
        int a; cin >> a;
        dp |= dp << a;
    }
    cout << dp.count()-1 << endl;
    for (int k = 1; k <= 1e5; ++k) {
        if (dp[k]) cout << k << ' ';
    }
    cout << endl;
}