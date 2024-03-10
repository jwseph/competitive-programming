#include <bits/stdc++.h>
using namespace std;

#define MAXN 200005

int N, A[MAXN];

int main() {
    cin >> N;
    for (int i = 0; i < N; ++i) cin >> A[i];
    sort(A, A+N);
    int res = 1;
    for (int i = 0; i < N-1; ++i) {
        res += A[i] != A[i+1];
    }
    cout << res << endl;
}