#include <bits/stdc++.h>
using namespace std;

#define MAXK 8
#define MAXE 20

int N, K, E, cnt[MAXK]{};
vector<pair<int, int>> R[MAXE];

bool fits(vector<pair<int, int>> v) {
    for (auto [c, k]: v) {
        if (cnt[k] < c) return 0;
    }
    return 1;
}

int sol(int i) {
    if (i == N) {
        for (int e = 0; e < E; ++e) {
            if (fits(R[e])) return 1;
        }
        return 0;
    }
    int res = 0;
    for (int k = 0; k < K; ++k) {
        cnt[k]++;
        res += sol(i+1);
        cnt[k]--;
    }
    return res;
}

int main() {
    cin >> N >> K >> E;
    for (int e = 0; e < E; ++e) {
        string T; cin >> T; T += '+';
        int i = 0, x = 0;
        for (int j = 1; j < T.size(); ++j) {
            if (T[j] == 'x') x = j;
            if (T[j] != '+') continue;
            int c = stoi(T.substr(i, x-i));
            int k = stoi(T.substr(x+1, j-(x+1)))-1;
            R[e].push_back({c, k});
            i = j+1;
        }
    }
    cout << sol(0) << endl;
}