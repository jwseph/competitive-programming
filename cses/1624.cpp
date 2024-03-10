#include <bits/stdc++.h>
using namespace std;

const int N = 8;

string A[N];
int VC[N], VD1[2*N-1], VD2[2*N-1];

int sol(int r) {
    if (r == N) return 1;
    int res = 0;
    for (int c = 0; c < N; ++c) {
        int d1 = r+c, d2 = r-c+N-1;
        if (VC[c] || VD1[d1] || VD2[d2] || A[r][c] == '*') continue;
        VC[c] = VD1[d1] = VD2[d2] = 1;
        res += sol(r+1);
        VC[c] = VD1[d1] = VD2[d2] = 0;
    }
    return res;
}

int main() {
    for (int r = 0; r < N; ++r) {
        cin >> A[r];
    }
    cout << sol(0) << endl;
}