#include <bits/stdc++.h>
using namespace std;

const int MAXN = 2e5+5;

int N, K, A[MAXN];

int main() {
    cin >> N >> K;
    for (int i = 0; i < N; ++i) cin >> A[i];
    int res = 0;
    for (int i = 0, j = 0; j < N; ++j) {
        K -= A[j];
        while (K < 0) K += A[i++];
        res += K == 0;
    }
    cout << res << endl;
}