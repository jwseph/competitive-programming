#include <bits/stdc++.h>
using namespace std;

int MOD = 1e9+7;

struct Trie {
    Trie* adj[26]{};
    bool end = 0;
};

int N, K, dp[5003];
string S;

Trie* tr = new Trie;

int sol(int i) {
    if (dp[i] >= 0) return dp[i];
    Trie* cur = tr;
    int res = 0;
    for (int j = i; j < N && cur->adj[S[j]-'a']; ++j) {
        cur = cur->adj[S[j]-'a'];
        if (cur->end) {
            res = (res+sol(j+1)) % MOD;
        }
    }
    return dp[i] = res;
}

int main() {
    memset(dp, -1, sizeof dp);
    cin >> S >> K;
    N = S.size();
    dp[N] = 1;
    while (K--) {
        string T; cin >> T;
        Trie* cur = tr;
        for (char c: T) {
            if (!cur->adj[c-'a']) cur->adj[c-'a'] = new Trie;
            cur = cur->adj[c-'a'];
        }
        cur->end = 1;
    }
    cout << sol(0) << endl;
}