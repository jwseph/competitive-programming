#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const int MAXN = 2e5+5;

int N, A[MAXN];

int main() {
    cin >> N;
    for (int i = 0; i < N; ++i) cin >> A[i];
    sort(A, A+N);
    ll res = 0;
    for (int i = 0; i < N; ++i) {
        res += abs(A[i]-A[N/2]);
    }
    cout << res << endl;
}