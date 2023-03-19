#include <bits/stdc++.h>
using namespace std;

#define MAXN 100'000
#define ll long long

int N, X, Y, Z, A[MAXN], B[MAXN];

int main() {
    cin >> N >> X >> Y >> Z;
    for (int i = 0; i < N; ++i) {
        cin >> A[i] >> B[i];
    }
    sort(A, A+N);
    sort(B, B+N);
    int i = 0, j = 0;
    ll res = 0;
    while (i < N && j < N) {
        if (A[i] <= B[j]) ++i;
        else ++j;
        ll cur = (ll)j*Z+(i-j)*Y+(N-i)*X;
        res = max(res, cur);
    }
    cout << res << endl;
}