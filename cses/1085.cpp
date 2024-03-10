#include <bits/stdc++.h>
using namespace std;

const int MAXN = 2e5+5;
using ll = long long;

int N, K, A[MAXN];

bool sol(ll m) {
    int res = 1;
    ll cur = 0;
    for (int i = 0; i < N; ++i) {
        cur += A[i];
        if (cur > m) {
            cur = A[i];
            ++res;
        }
        if (cur > m) return 0;
    }
    return res <= K;
}

int main() {
    cin >> N >> K;
    ll l = 0, r = 0;
    for (int i = 0; i < N; ++i) {
        cin >> A[i];
        r += A[i];
    }
    while (l < r) {
        ll h = (l+r)/2;
        if (sol(h)) r = h;
        else l = h+1;
    }
    cout << l << endl;
}