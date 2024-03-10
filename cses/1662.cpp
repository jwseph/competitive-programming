#include <bits/stdc++.h>
using namespace std;

const int MAXN = 2e5+5;
using ll = long long;

int N, cnt[MAXN];

int main() {
    cin >> N;
    int p = 0;
    ll res = 0;
    cnt[0] = 1;
    for (int i = 0; i < N; ++i) {
        int a; cin >> a;
        p = ((p+a)%N+N)%N;
        res += cnt[p]++;
    }
    cout << res << endl;
}