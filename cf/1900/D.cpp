#include <bits/stdc++.h>
using namespace std;

#define MAXN 80000
#define ll long long

int GCD(int a, int b) {
    return a%b == 0 ? b : GCD(b, a%b);
}

int NT, N, A[MAXN];

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> NT;
    while (NT--) {
        cin >> N;
        for (int i = 0; i < N; ++i) {
            cin >> A[i];
        }
        sort(A, A+N);
        ll res = 0;
        for (int i = 0; i < N; ++i) {
            for (int j = 0; j < i; ++j) {
                res += (ll) (N-1-i) * GCD(A[i], A[j]);
            }
        }
        cout << res << endl;
    }
}