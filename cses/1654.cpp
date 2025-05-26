#include <bits/stdc++.h>
using namespace std;

const int M = 1<<20;
int n;
int a[M], dp1[M], dp2[M];

int main() {
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        dp1[a[i]] = ++dp2[a[i]];
    }
    for (int i = 0; i < 20; ++i) {
        for (int x = 0; x < M; ++x) {
            if (x&1<<i) dp1[x] += dp1[x^1<<i];
            else dp2[x] += dp2[x^1<<i];
        }
    }
    for (int i = 0; i < n; ++i) {
        cout << dp1[a[i]] << ' ' << dp2[a[i]] << ' ' << n-dp1[a[i]^M-1] << endl;
    }
}