#include <bits/stdc++.h>
using namespace std;

int N;
unordered_map<string, int> cnt, dup;

int main() {
    cin >> N;
    for (int i = 0; i < N; ++i) {
        string S, C; cin >> S >> C;
        S = S.substr(0, 2);
        string s = S + C;
        if (cnt.find(s) == cnt.end()) cnt[s] = 0;
        ++cnt[s];
        if (S == C) {
            if (dup.find(S) == dup.end()) dup[S] = 0;
            ++dup[S];
        }
    }
    int res = 0;
    for (const auto &p: cnt) {
        string s = p.first.substr(2) + p.first.substr(0, 2);
        if (cnt.find(s) != cnt.end()) {
            res += p.second * cnt[s];
        }
    }
    for (const auto& p: dup) {
        res -= p.second * p.second;
    }
    res /= 2;
    cout << res << endl;
}