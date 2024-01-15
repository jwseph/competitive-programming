#include <bits/stdc++.h>
using namespace std;

int MOD = 1e9+7;

int N, K;
string S;

int t[1000006][26]{}, ts = 1;
bool s[1000006]{};
void insert(string T) {
    int p = 0;
    for (char c: T) {
        if (!t[p][c-'a']) t[p][c-'a'] = ts++;
        p = t[p][c-'a'];
    }
    s[p] = 1;
}

int main() {
    cin >> S >> K;
    N = S.size();
    while (K--) {
        string T; cin >> T;
        insert(T);
    }
    int dp[N+1];
    dp[N] = 1;
    for (int i = N-1; i >= 0; --i) {
        dp[i] = 0;
        int p = 0;
        for (int j = i; j < N && t[p][S[j]-'a']; ++j) {
            p = t[p][S[j]-'a'];
            if (s[p]) {
                dp[i] = (dp[i]+dp[j+1]) % MOD;
            }
        }
    }
    cout << dp[0] << endl;
}