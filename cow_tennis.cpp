#include <bits/stdc++.h>
using namespace std;

int N, A[5000];

int main() {
    cin >> N;
    for (int i = 0; i < N; ++i) {
        cin >> A[i];
    }
    sort(A, A+N);
    long long res = 0;
    for (int i = 0; i < N; ++i) {
        for (int j = i+1; j < N; ++j) {
            int dif = A[j]-A[i];
            int cur = upper_bound(A, A+N, A[j]+2*dif)
                    - lower_bound(A, A+N, A[j]+dif);
            res = max(res, res+cur);
        }
    }
    cout << res << endl;
}