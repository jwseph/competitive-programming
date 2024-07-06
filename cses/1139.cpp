#include <bits/stdc++.h>
using namespace std;

const int MAXN = 2e5+5;
int N;
vector<int> A[MAXN];
int R[MAXN];
set<int> S[MAXN];

void dfs(int i, int p) {
    for (int j: A[i]) {
        if (j == p) continue;
        dfs(j, i);
        if (S[i].size() < S[j].size()) swap(S[i], S[j]);
        S[i].merge(S[j]);
    }
    R[i] = S[i].size();
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin >> N;
    for (int i = 1; i <= N; ++i) {
        int c; cin >> c;
        S[i].insert(c);
    }
    for (int e = 0; e < N-1; ++e) {
        int i, j; cin >> i >> j;
        A[i].push_back(j), A[j].push_back(i);
    }
    dfs(1, -1);
    for (int i = 1; i <= N; ++i) {
        cout << R[i] << ' ';
    }
    cout << endl;
}