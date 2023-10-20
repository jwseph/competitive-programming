#include <bits/stdc++.h>
using namespace std;

#define MAXN 1'000'000
#define MAXK 25'000

int N, K, A[MAXN], L[MAXK], R[MAXK];

int main() {
    cin >> N >> K;
    for (int k = 0; k < K; ++k) {
        cin >> L[k] >> R[k];
    }
    sort(L, L+K);
    sort(R, R+K);
    for (int i = 0; i < N; ++i) {
        int l = lower_bound(R, R+K, i+1) - R;
        int r = upper_bound(L, L+K, i+1) - L;
        A[i] = r-l;
    }
    sort(A, A+N);
    cout << A[N/2] << endl;
}