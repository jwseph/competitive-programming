#include <bits/stdc++.h>
using namespace std;

const int N = 1e6+5, K = 1e2+5;
int n, k;
int ar[K];
bool dp[N];

int main() {
    cin >> n >> k;
    for (int s = 0; s < k; ++s) cin >> ar[s];
    sort(ar, ar+k);
    for (int i = 1; i <= n; ++i) {
        for (int s = 0; s < k && i >= ar[s]; ++s) {
            dp[i] |= !dp[i-ar[s]];
        }
        cout << (dp[i] ? 'W' : 'L');
    }
    cout << endl;
}