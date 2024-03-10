#include <bits/stdc++.h>
using namespace std;

const int MAXN = 2e5+5;
int N, K = 0, dp[MAXN];

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin >> N;
    while (N--) {
        int a; cin >> a;
        int i = lower_bound(dp, dp+K, a) - dp;
        if (i == K) ++K;
        dp[i] = a;
    }
    cout << K << endl;
}