#include <bits/stdc++.h>
using namespace std;

const int MAXK = 15, MAXN = 1<<MAXK;
int K, N;
queue<pair<int, int>> A[MAXN];
stack<int> res;

void dfs(int i) {
    while (A[i].size()) {
        auto [j, b] = A[i].front(); A[i].pop();
        dfs(j);
        res.push(b);
    }
}

int main() {
    cin >> K; --K;
    N = 1<<K;
    for (int i = 0; i < N; ++i) {
        A[i].push({i<<1 & N-1, 0});
        A[i].push({i<<1 & N-1 | 1, 1});
    }
    dfs(0);
    while (K--) res.push(0);
    while (res.size()) {
        int i = res.top(); res.pop();
        cout << i;
    }
    cout << endl;
}