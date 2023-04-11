#include <bits/stdc++.h>
using namespace std;

#define MAXN 100

int N, A[MAXN];

int main() {
    freopen("crossroad.in", "r", stdin);
    freopen("crossroad.out", "w", stdout);
    cin >> N;
    memset(A, -1, sizeof A);
    int res = 0;
    for (int i = 0; i < N; ++i) {
        int C, S; cin >> C >> S;
        if (A[C] >= 0 && A[C] == 1-S) {
            ++res;
        }
        A[C] = S;
    }
    cout << res << endl;
}