#include <bits/stdc++.h>
using namespace std;

const int MAXN = 2e5+5;

int N, K, A[MAXN];

int main() {
    cin >> N >> K;
    for (int i = 0; i < N; ++i) cin >> A[i];
    sort(A, A+N);
    int res = 0;
    for (int i = 0, j = N-1; i <= j; --j, ++res) {
        if (i < j && A[i]+A[j] <= K) ++i;
    }
    cout << res << endl;
}