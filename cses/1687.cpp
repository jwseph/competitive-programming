#include <bits/stdc++.h>
using namespace std;

const int MAXN = 2e5+5;
int N, M;
int P[MAXN][20];

int query(int i, int k) {
    for (int b = 0; k>>b; ++b) {
        if (k>>b&1) i = P[i][b];
    }
    return i ? i : -1;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin >> N >> M;
    for (int i = 2; i <= N; ++i) {
        cin >> P[i][0];
    }
    for (int k = 1; k < 20; ++k) {
        for (int i = 1; i <= N; ++i) {
            P[i][k] = P[P[i][k-1]][k-1];
        }
    }
    while (M--) {
        int i, k; cin >> i >> k;
        cout << query(i, k) << endl;
    }
}