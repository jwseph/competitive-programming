#include <bits/stdc++.h>
using namespace std;

#define MAXN 100

int N, M;
vector<int> W[MAXN], L[MAXN];
int V[MAXN]{};

int dfs(vector<int>* A, int i, int v) {
    if (V[i] == v) return 0;
    V[i] = v;
    int res = 1;
    for (int j: A[i]) res += dfs(A, j, v);
    return res;
}

int main() {
    // If the number of nodes worse or better than node i is equal to N-1,
    // then you know node i's position
    cin >> N >> M;
    while (M--) {
        int i, j; cin >> i >> j; --i; --j;
        W[i].push_back(j);
        L[j].push_back(i);
    }
    int res = 0;
    for (int i = 0; i < N; ++i) {
        res += dfs(W, i, 2*i+1) + dfs(L, i, 2*i+2) == N+1;
    }
    cout << res << endl;
}