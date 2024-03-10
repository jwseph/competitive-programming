#include <bits/stdc++.h>
using namespace std;

const int MAXK = 1e5+5;
int N;
bool dp[MAXK];

int main() {
    cin >> N;
    dp[0] = 1;
    int res = 0;
    while (N--) {
        int a; cin >> a;
        for (int k = 1e5; k >= a; --k) {
            res += !dp[k] && dp[k-a];
            dp[k] |= dp[k-a];
        }
    }
    cout << res << endl;
    for (int k = 1; k <= 1e5; ++k) {
        if (dp[k]) cout << k << ' ';
    }
    cout << endl;
}