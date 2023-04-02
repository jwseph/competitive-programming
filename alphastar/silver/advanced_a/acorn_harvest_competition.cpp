#include <bits/stdc++.h>
using namespace std;

#define MAX3N 3*500'000
#define ll long long

int N, A[MAX3N], U[MAX3N], W[MAX3N];
ll a, b, c, d, e, f, g, h, M;

ll pow(ll i, int p, ll m) {
    ll res = 1;
    while (p--) res = res*i % m;
    return res;
}

bool cmp(int l, int r) {
    if (U[l] != U[r]) return U[l] > U[r];
    return W[l] < W[r];
}

int main() {
    cin >> N >> a >> b >> c >> d >> e >> f >> g >> h >> M;
    for (int i = 0; i < 3*N; ++i) {
        A[i] = i;
        W[i] = ((a*pow(i, 5, d)%d + b*pow(i, 2, d)%d) % d + c) % d;
        U[i] = ((e*pow(i, 5, h)%h + f*pow(i, 3, h)%h) % h + g) % h;
    }
    partial_sort(A, A+N, A+3*N, cmp);
    ll res = 0;
    for (int i = 0; i < N; ++i) {
        res = (res+W[A[i]]) % M;
    }
    cout << res << endl;
}