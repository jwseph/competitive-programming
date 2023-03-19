#include <bits/stdc++.h>
using namespace std;

#define M_MAX 200'000
#define ll long long

int N, M;
pair<ll, ll> A[M_MAX];

bool sol(ll D) {
    int i = 0, a = 0;
    ll pos = A[0].first;
    while (i < M && a < N) {
        if (pos > A[i].second) {
            ++i;
            continue;
        }
        if (pos < A[i].first) {
            pos = A[i].first;
        }
        ++a;
        pos += D;
    }
    return a == N;
}

int main() {
    cin >> N >> M;
    for (int i = 0; i < M; ++i) {
        cin >> A[i].first >> A[i].second;
    }
    sort(A, A+M);
    ll l = 0, r = 1'000'000'000'000'000'000ll;
    while (l < r) {
        ll h = (l+r)/2ll;
        if (sol(h)) l = h+1ll;
        else r = h;
    }
    cout << l-1 << endl;
}