#include <bits/stdc++.h>
using namespace std;

#define MAXN 21
#define ll long long

int N, A[MAXN];

ll sol(int i, ll d) {
    if (i == N || d < 0) return abs(d);
    return min(sol(i+1, d), sol(i+1, d-2*A[i]));
}

int main() {
    cin >> N;
    ll d = 0;
    for (int i = 0; i < N; ++i) {
        cin >> A[i];
        d += A[i];
    }
    sort(A, A+N);
    cout << sol(0, d) << endl;
}