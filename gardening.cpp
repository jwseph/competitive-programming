#include <bits/stdc++.h>
using namespace std;

#define N_MAX 100'000

int N, res = -1;
vector<int> adj[N_MAX];

void dfs(int i, int p) {
    int cur = 1+adj[i].size();
    res = max(res, cur);
    for (int& j: adj[i]) {
        if (j == p) continue;
        dfs(j, i);
    }
}

int main() {
    // Problem can be reduced to maximum edges of any node
    cin >> N;
    for (int i = 0; i < N-1; ++i) {
        int A, B; cin >> A >> B; --A; --B;
        adj[A].push_back(B);
        adj[B].push_back(A);
    }
    dfs(0, -1);
    cout << res << endl;
}