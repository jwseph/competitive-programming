#include <bits/stdc++.h>
using namespace std;

const int MAXN = 2e5+5;
using ll = long long;

int N, K;
map<ll, ll> cnt;

int main() {
    cin >> N >> K;
    ll p = 0, res = 0;
    cnt[p] = 1;
    for (int i = 0; i < N; ++i) {
        int a; cin >> a;
        p += a;
        res += cnt[p-K];
        cnt[p]++;
    }
    cout << res << endl;
}