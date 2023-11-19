#include <bits/stdc++.h>
using namespace std;

#define MAXN 100'000

int N, A[MAXN];

int main() {
    cin >> N;
    for (int i = 0; i < N; ++i) {
        cin >> A[i];
    }
    sort(A, A+N);
    int res1 = INT_MAX;
    for (int i = 0, j = 0; j < N; ++j) {
        while (A[j]-A[i]+1 > N) ++i;
        bool extra = (i == 0 || j == N-1) && A[j]-A[i]+1 < N;
        res1 = min(res1, N-(j-i+1) + extra);
    }
    cout << res1 << endl;
    int res2 = A[N-1]-A[0]+1-N - min(A[1]-A[0]-1, A[N-1]-A[N-2]-1);
    cout << res2 << endl;
}