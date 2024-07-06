#include <bits/stdc++.h>
using namespace std;

const int MAXN = 5e2+5;
int N, M;
map<int, int> A[MAXN], O[MAXN];
bool V[MAXN];
vector<int> cur;

int sol(int i, int w) {
    if (i == N-1) return w;
    if (V[i]) return 0;
    V[i] = 1;
    for (auto [j, dw]: A[i]) {
        int cut = sol(j, min(w, dw));
        if (cut) {
            A[i][j] -= cut;
            A[j][i] += cut;
            if (!A[i][j]) A[i].erase(j);
            return cut;
        }
    }
    return 0;
}

void dfs(int i) {
    cur.push_back(i);
    if (i == N-1) return;
    for (auto [j, w]: O[i]) {
        if (!A[i][j]) {
            O[i].erase(j);
            dfs(j);
            return;
        }
    }
}

int main() {
    cin >> N >> M;
    for (int e = 0; e < M; ++e) {
        int i, j; cin >> i >> j; --i, --j;
        A[i][j]++;
        O[i][j]++;
    }
    int res = 0;
    while (sol(0, INT_MAX)) {
        ++res;
        memset(V, 0, sizeof V);
    }
    cout << res << endl;
    while (res--) {
        cur = {};
        dfs(0);
        cout << cur.size() << endl;
        for (int i: cur) cout << i+1 << ' ';
        cout << endl;
    }
}