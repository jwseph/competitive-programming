#include <bits/stdc++.h>
using namespace std;

#define MAXN 200005

int N, res = 0;
vector<int> A[MAXN];

bool dfs(int i, int p) {
    bool f = 0;
    for (int j: A[i]) {
        if (j == p) continue;
        f |= dfs(j, i);
    }
    res += f;
    return !f;
}

int main() {
    cin >> N;
    for (int e = 0; e < N-1; ++e) {
        int i, j; cin >> i >> j; --i; --j;
        A[i].push_back(j);
        A[j].push_back(i);
    }
    dfs(0, -1);
    cout << res << endl;
}