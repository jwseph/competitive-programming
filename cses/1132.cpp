#include <bits/stdc++.h>
using namespace std;

using pii = array<int, 2>;

const int MAXN = 2e5+5;
int N;
vector<int> A[MAXN];
int R[MAXN];

pii dfs(int i, int p = -1, int t = 0) {
    R[i] = max(R[i], t);
    pii res = {t, i};
    for (int j: A[i]) {
        if (j == p) continue;
        res = max(res, dfs(j, i, t+1));
    }
    return res;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin >> N;
    for (int e = 0; e < N-1; ++e) {
        int i, j; cin >> i >> j; --i, --j;
        A[i].push_back(j), A[j].push_back(i);
    }
    dfs(dfs(dfs(0)[1])[1]);
    for (int i = 0; i < N; ++i) cout << R[i] << ' ';
    cout << endl;
}