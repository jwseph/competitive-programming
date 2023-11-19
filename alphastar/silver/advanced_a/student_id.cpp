#include <bits/stdc++.h>
using namespace std;

#define MAXN 50'000
#define ll long long

int N, L[7], R[7];

int main() {
    memset(L, -1, sizeof L);
    memset(R, -1, sizeof R);
    cin >> N;
    int p = 0, res = 0;
    L[p] = R[p] = 0;
    for (int i = 0; i < N; ++i) {
        int cur; cin >> cur;
        p = (p+cur)%7;
        if (L[p] < 0) L[p] = i+1;
        R[p] = i+1;
        res = max(res, R[p]-L[p]);
    }
    cout << res << endl;
}