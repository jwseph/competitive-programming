#include <bits/stdc++.h>
using namespace std;

using ll = long long;

const int MAXN = 1e3+5;
int B, G, N, M;
map<int, ll> A[MAXN];
int V[MAXN], v = 1;

ll sol(int i, ll w) {
    if (i == N) return w;
    if (V[i] == v) return 0;
    V[i] = v;
    for (auto [j, w0]: A[i]) {
        ll cut = sol(j, min(w, w0));
        if (cut) {
            A[i][j] -= cut;
            A[j][i] += cut;
            if (!A[i][j]) A[i].erase(j);
            return cut;
        }
    }
    return 0;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin >> B >> G >> M;
    N = B+G+1;
    for (int i = 1; i <= B; ++i) {
        A[0][i]++;
    }
    for (int j = B+1; j <= B+G; ++j) {
        A[j][N]++;
    }
    for (int e = 0; e < M; ++e) {
        int i, j; cin >> i >> j;
        j += B;
        A[i][j] = 1;
    }
    int cur = 0, res = 0;
    while (cur = sol(0, LLONG_MAX)) {
        v++;
        res += cur;
    }
    cout << res << endl;
    for (int j = B+1; j <= B+G; ++j) {
        for (auto [i, w]: A[j]) {
            if (i != N && !A[i][j]) cout << i << ' ' << j-B << endl;
        }
    }
}