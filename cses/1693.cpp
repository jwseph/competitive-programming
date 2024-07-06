#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e5+5;
int N, M, IN[MAXN];
vector<int> A[MAXN], res;

void dfs(int i) {
    while (A[i].size()) {
        int j = A[i].back(); A[i].pop_back();
        dfs(j);
    }
    res.push_back(i);
}

bool sol() {
    for (int i = 1; i <= N; ++i) {
        if (IN[i]) return 0;
    }
    dfs(N);
    if (res.size() < M+1) return 0;
    for (int i: res) cout << i << ' ';
    cout << endl;
    return 1;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin >> N >> M;
    IN[1]++, IN[N]--;
    for (int e = 0; e < M; ++e) {
        int i, j; cin >> i >> j;
        A[j].push_back(i);
        IN[i]--, IN[j]++;
    }
    if (!sol()) cout << "IMPOSSIBLE" << endl;
}