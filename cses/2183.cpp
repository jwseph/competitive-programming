#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const int MAXN = 2e5+5;

int N, A[MAXN];

int main() {
    cin >> N;
    for (int i = 0; i < N; ++i) cin >> A[i];
    sort(A, A+N);
    ll res = 1;
    for (int i = 0; i < N && A[i] <= res; ++i) {
        res += A[i];
    }
    cout << res << endl;
}