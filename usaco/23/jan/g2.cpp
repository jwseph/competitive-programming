#include <bits/stdc++.h>
using namespace std;

#define MAXN 20
#define MAXT 65

int NT, N;
bool dp[MAXT][1<<MAXN]{};

int read_bs() {
    string S; cin >> S;
    int res = 0;
    for (char c: S) res = res<<1 | c-'0';
    return res;
}

int shift(int x, int k) {
    k %= N;
    return x>>k | (x&(1<<k)-1)<<(N-k);
}

int main() {
    // Switches don't matter because you can calculate their effects separately
    cin.tie(0)->sync_with_stdio(0);
    cin >> NT >> N;
    int m = 0;
    dp[0][0] = 1;
    for (int t = 0; t < 3*N; ++t) {
        m = 1^shift(m, 1);
        for (int i = 0; i < (1<<N); ++i) {
            if (!dp[t][i]) continue;
            for (int p = 0; p < N; ++p) {
                int j = i^shift(m, p);
                dp[t+1][j] = 1;
            }
        }
    }
    while (NT--) {
        int l = read_bs(), s = read_bs();
        for (int t = 0; t <= 3*N; ++t) {
            if (dp[t][l]) {
                cout << t << endl;
                break;
            }
            l ^= s;
            s = shift(s, 1);
        }
    }
}