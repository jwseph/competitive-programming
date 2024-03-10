#include <bits/stdc++.h>
using namespace std;

const int MAXN = 2e5+5;
int N, Q;
int P[MAXN][30];

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin >> N >> Q;
    for (int i = 1; i <= N; ++i) {
        int j; cin >> j;
        P[i][0] = j;
    }
    for (int p = 1; p < 30; ++p) {
        for (int i = 1; i <= N; ++i) {
            P[i][p] = P[P[i][p-1]][p-1];
        }
    }
    while (Q--) {
        int i, k; cin >> i >> k;
        for (int p = 0; p < 30; ++p) {
            if (k&1<<p) i = P[i][p];
        }
        cout << i << endl;
    }
}