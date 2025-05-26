#include <bits/stdc++.h>
using namespace std;

using ll = long long;

const int mod = 1e9+7;
int n;
string s;
ll dp[500005], vst[256];

int main() {
    cin >> s;
    n = s.size();
    for (int c = 0; c < 256; ++c) {
        vst[c] = n+1;
    }
    dp[n] = 1;
    for (int i = n-1; i >= 0; --i) {
        dp[i] = (dp[i+1] * 2 - dp[vst[s[i]]+1]) % mod;
        vst[s[i]] = i;
    }
    cout << (dp[0]-1+mod)%mod << endl;
}