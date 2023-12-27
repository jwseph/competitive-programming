#include <bits/stdc++.h>
using namespace std;

#define MAXN 100005
#define ll long long

int N, A[MAXN];

int main() {
    cin >> N;
    for (int i = 0; i < N; ++i) cin >> A[i];
    sort(A, A+N);
    ll res = INT_MIN;
    int bp = 0;
    for (int i = 0; i < N; ++i) {
        ll cur = (ll) A[i]*(N-i);
        if (cur > res) {
            res = cur;
            bp = A[i];
        }
    }
    cout << res << ' ' << bp << endl;
}