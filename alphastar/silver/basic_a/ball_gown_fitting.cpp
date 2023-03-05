#include <bits/stdc++.h>
using namespace std;

#define N_MAX 100'000

int N, S, A[N_MAX];

int main() {
    cin >> N >> S;
    for (int i = 0; i < N; ++i) {
        cin >> A[i];
    }
    sort(A, A+N);
    int res = 0;
    for (int i = 0, j = N-1; i < j;) {
        if (A[i]+A[j] <= S) {
            res += j-i;
            ++i;
        } else {
            --j;
        }
    }
    cout << res << endl;
}