#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using t3i = array<int, 3>;

const int MAXN = 2e5+5;
int N;
t3i A[MAXN];
ll dp[MAXN];

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin >> N;
    for (int i = 0; i < N; ++i) {
        cin >> A[i][0] >> A[i][1] >> A[i][2];
    }
    sort(A, A+N);
    for (int i = N-1; i >= 0; --i) {
        auto [l, r, t] = A[i];
        t3i p = {r, INT_MAX, 0};
        int j = upper_bound(A, A+N, p) - A;
        dp[i] = max(dp[i+1], t+dp[j]);
    }
    cout << dp[0] << endl;
}