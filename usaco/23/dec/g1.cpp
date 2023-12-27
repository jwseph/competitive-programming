#include <bits/stdc++.h>
using namespace std;

#define MAXN 752
#define ll long long

int N, A[MAXN][MAXN]{}, adj[MAXN][MAXN]{};
int dp[MAXN][MAXN]{};

int main() {
    cin >> N;
    for (int i = 0; i < N-1; ++i) {
        string S; cin >> S;
        for (int j = i+1; j < N; ++j) {
            A[i][j] = S[j-i-1] == '1' ? 1 : 0;
        }
    }
    ll res = 0;
    for (int d = 1; d < N; ++d) {
        for (int i = 0; i < N-d; ++i) {
            int j = i+d;
            for (int k = i+1; k <= j-1; ++k) {
                if (adj[k][j]) dp[i][j] += dp[i][k];
                dp[i][j] %= 2;
            }
            if (dp[i][j] != A[i][j]) {
                adj[i][j] = 1;
                ++res;
                ++dp[i][j];
                dp[i][j] %= 2;
            }
        }
    }
    cout << res << endl;
}