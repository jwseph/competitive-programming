#include <bits/stdc++.h>
using namespace std;

#define MAXN 200005

int N, res[MAXN];
vector<int> A[MAXN];

int dfs(int i) {
    res[i] = 0;
    for (int j: A[i]) res[i] += 1+dfs(j);
    return res[i];
}

int main() {
    cin >> N;
    for (int j = 1; j < N; ++j) {
        int i; cin >> i; --i;
        A[i].push_back(j);
    }
    dfs(0);
    for (int i = 0; i < N; ++i) cout << res[i] << ' ';
    cout << endl;
}