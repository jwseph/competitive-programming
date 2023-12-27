#include <bits/stdc++.h>
using namespace std;

#define MOD 1000000007
#define ll long long
#define MAXX 2000006

int exp(int a, int b) {
    int res = 1;
    while (b) {
        if (b&1) res = (ll)res*a % MOD;
        a = (ll)a*a % MOD;
        b >>= 1;
    }
    return res;
}

ll fac[MAXX+1];
void factorial() {
    fac[0] = 1;
    for (int i = 1; i <= MAXX; ++i) fac[i] = fac[i-1] * i % MOD;
}

ll inv[MAXX+1];
void inverses() {
    inv[MAXX] = exp(fac[MAXX], MOD-2);
    for (int i = MAXX; i >= 1; --i) inv[i-1] = inv[i] * i % MOD;
}

int choose(int n, int k) {
    return fac[n] * inv[k] % MOD * inv[n-k] % MOD;
}

#define MAXN 100005

int N, A[MAXN]{};
int res = 1;
unordered_map<int, int> cnt;

void sol(int l) {
    // cout << "A[" << l << "]=" << A[l] << " res=" << res << endl;
    int take = INT_MAX;
    int r = l;
    while (r < N && A[r]) {
        take = min(take, A[r]);
        ++r;
    }
    // cout << "take=" << take << endl;
    // cout << res << endl;
    // cout << "cnt=" << cnt[l] << endl;
    // cout << "choose(" << cnt[l]+take/2 << ", " << take/2 << endl;
    res *= choose(cnt[l]+take/2-1, take/2);
    for (int i = l; i < r; ++i) {
        A[i] -= take;
        cnt[i] += take;
    }
    cnt[r] += take/2;
    for (int i = l; i < r; ++i) {
        if (A[i]) sol(i);
    }
}

int main() {
    factorial();
    inverses();

    cin >> N;
    for (int i = 0; i < N; ++i) cin >> A[i];
    cnt[0] = 1;
    sol(0);
    cout << res << endl;
}