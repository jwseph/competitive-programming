#include <bits/stdc++.h>
using namespace std;

const int MAXN = 2e5+5;

int N, Q, idx[MAXN], A[MAXN];

int main() {
    cin >> N >> Q;
    for (int i = 0; i < N; ++i) {
        int a; cin >> a; --a;
        idx[a] = i;
        A[i] = a;
    }
    int res = 1;
    for (int a = 0; a+1 < N; ++a) {
        res += idx[a] > idx[a+1];
    }
    while (Q--) {
        int i, j; cin >> i >> j; --i; --j;
        int a = A[i], b = A[j];
        set<int> P = {a-1, a, b-1, b};
        for (int p: P) {
            if (p < 0 || p+1 >= N) continue;
            res -= idx[p] > idx[p+1];
        }
        swap(A[i], A[j]);
        swap(idx[a], idx[b]);
        for (int p: P) {
            if (p < 0 || p+1 >= N) continue;
            res += idx[p] > idx[p+1];
        }
        cout << res << endl;
    }
}