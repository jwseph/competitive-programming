#include <bits/stdc++.h>
using namespace std;

const int MAXN = 2e5+5;
using ll = long long;

int N, A[MAXN];

int main() {
    cin >> N;
    ll res = 0;
    for (int i = 0; i < N; ++i) {
        cin >> A[i];
        int b; cin >> b;
        res += b;
    }
    sort(A, A+N);
    for (int i = 0; i < N; ++i) {
        res -= (ll)(N-i)*A[i];
    }
    cout << res << endl;
}