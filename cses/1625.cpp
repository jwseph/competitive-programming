#include <bits/stdc++.h>
using namespace std;

#define ll long long

int dr[4] = {-1, 1, 0, 0}, dc[4] = {0, 0, -1, 1};
ll R = 2, C = 2;
string S, T = "UDLR";

int sol(int r, int c, ll v, int i) {
    if (v == (1ll<<R*C)-1) {
        return r == R-1 && c == 0;
    }
    int res = 0;
    for (int d = 0; d < 4; ++d) {
        if (S[i] != '?' && T[d] != S[i]) continue;
        int i = r+dr[d], j = c+dc[d];
        if (i < 0 || i >= R || j < 0 || j >= C) continue;
        ll p = i*C+j;
        if (v&1ll<<p) continue;
        res += sol(i, j, v|1ll<<p, i+1);
    }
    return res;
}

int main() {
    cin >> S;
    cout << sol(0, 0, 1, 0) << endl;
}