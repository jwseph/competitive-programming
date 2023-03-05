#include <bits/stdc++.h>
using namespace std;

int M, N, A[9];
unordered_set<int> U;

void dfs(int i, int res) {
    if (i == N) {
        cout << res << endl;
        return;
    }
    for (int j = 0; j < M; ++j) {
        dfs(i+1, res*10+A[j]);
    }
}

int main() {
    cin >> M;
    for (int i = 0; i < M; ++i) {
        cin >> A[i];
    }
    cin >> N;
    dfs(0, 0);
}