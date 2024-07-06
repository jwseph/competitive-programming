#include <bits/stdc++.h>
using namespace std;

#define MAXN 200005
#define pii pair<int, int>

string S, T = "bessie";
int N, A[MAXN];
pii dp[MAXN][6];

int main() {
    cin >> S;
    N = S.size();
    for (int i = 0; i < N; ++i) cin >> A[i];

    for (int i = N-1; i >= 0; --i) {
        for (int j = 0; j < 6; ++j) {
            pii p = dp[i+1][j];
            if (j) p.second += A[i];
            dp[i][j] = p;
            if (T[j] == S[i]) {
                pii q = dp[i+1][(j+1)%6];
                if (j+1 == 6) --q.first;
                dp[i][j] = min(dp[i][j], q);
            }
        }
    }

    pii res = dp[0][0];
    cout << -res.first << endl;
    cout << res.second << endl;
}