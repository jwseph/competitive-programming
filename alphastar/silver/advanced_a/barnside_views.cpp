#include <bits/stdc++.h>
using namespace std;

#define MAXN 80001

int N, A[MAXN];
stack<int> S;

int main () {
    // Barn i can see all barns before barn b such that h[i] <= h[b]
    cin >> N;
    for (int i = 0; i < N; ++i) {
        cin >> A[i];
    }
    A[N] = INT_MAX;
    S.push(N);
    long long res = 0;
    for (int i = N-1; i >= 0; --i) {
        while (A[S.top()] < A[i]) S.pop();
        res += S.top()-i-1;
        while (A[S.top()] == A[i]) S.pop();
        S.push(i);
    }
    cout << res << endl;
}