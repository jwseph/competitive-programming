#include <bits/stdc++.h>
using namespace std;

#define N_MAX 251

int N, M, cnt = 0;
vector<int> adj[N_MAX];
bool V[N_MAX] {};

void dfs(int i) {
    if (V[i]) return;
    ++cnt;
    V[i] = true;
    for (int j: adj[i]) {
        dfs(j);
    }
}

int main() {
    cin >> N >> M;
    for (int i = 0; i < M; ++i) {
        int A, B; cin >> A >> B;
        adj[A].push_back(B);
        adj[B].push_back(A);
    }
    dfs(1);
    if (cnt == N) cout << 0 << endl;
    for (int i = 1; i <= N; ++i) {
        if (!V[i]) cout << i << endl;
    }
}