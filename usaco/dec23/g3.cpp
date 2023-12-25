#include <bits/stdc++.h>
using namespace std;

#define MAXN 200005
#define ll long long

int N, NQ;
ll A[MAXN], P[MAXN], a, b;

ll calc2(int y) {
    int res = 0;
    for (int i = 0; i < N; ++i) {
        if (A[i] < y) res += (y-A[i])*a;
        else res += (A[i]-y)*b;
    }
    return res;
}

ll calc(ll y) {
    int l = lower_bound(A, A+N, y) - A;
    int r = upper_bound(A, A+N, y) - A;
    return a*(y*l-P[l]-P[0]) + b*(P[N]-P[r]-y*(N-r));
}

ll sol() {
    int l = A[0], r = A[N-1];
    while (l < r) {
        int h = (l+r)/2;
        if (calc(h) <= calc(h+1)) r = h;
        else l = h+1;
    }
    return calc(l);
}

int main() {
    cin >> N;
    for (int i = 0; i < N; ++i) cin >> A[i];
    sort(A, A+N);
    P[0] = 0;
    for (int i = 0; i < N; ++i) P[i+1] = P[i] + A[i];
    cin >> NQ;
    while (NQ--) {
        cin >> a >> b;
        cout << sol() << endl;
    }
}