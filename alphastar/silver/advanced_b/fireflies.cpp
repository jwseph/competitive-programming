#include <bits/stdc++.h>
using namespace std;

int N, C;
vector<int> R[2];
string S;
set<string> res;

void flip(int k) {
    for (int i = 0; i < N; ++i) {
        if (i%k == 0) {
            S[i] = '0'+('1'-S[i]);
        }
    }
}

void dfs(int c) {
    if (c == 0) {
        for (int i = 0; i < 2; ++i) {
            for (int j: R[i]) {
                if (S[j] != i+'0') return;
            }
        }
        res.insert(S);
        return;
    }
    flip(1);
    dfs(c-1);
    flip(2);
    dfs(c-1);
    flip(2);
    flip(1);
    flip(2);
    dfs(c-1);
    flip(2);
    flip(3);
    dfs(c-1);
    flip(3);
}

int main() {
    cin >> N >> C;
    for (int i = 1; i >= 0; --i) {
        int t; cin >> t;
        while (t >= 0) {
            R[i].push_back(t-1);
            cin >> t;
        }
    }
    S = string(N, '1');
    dfs(min(C, 4));
    for (const auto& s: res) {
        cout << s << endl;
    }
    if (res.empty()) {
        cout << "IMPOSSIBLE" << endl;
    }
}