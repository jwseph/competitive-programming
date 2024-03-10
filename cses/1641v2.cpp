#include <bits/stdc++.h>
using namespace std;

const int MAXN = 5e3+5;

int N, K;
array<int, 2> A[MAXN];

int main() {
    cin >> N >> K;
    for (int i = 0; i < N; ++i) {
        cin >> A[i][0];
        A[i][1] = i+1;
    }
    sort(A, A+N);
    for (int i = 0; i < N; ++i) {
        int cur = K-A[i][0];
        for (int j = i+1, k = N-1; j < k; ++j) {
            while (j < k && A[j][0]+A[k][0] > cur) --k;
            if (j < k && A[j][0]+A[k][0] == cur) {
                cout << A[i][1] << ' ' << A[j][1] << ' ' << A[k][1] << endl;
                return 0;
            }
        }
    }
    cout << "IMPOSSIBLE" << endl;
}