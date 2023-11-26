#include <bits/stdc++.h>
using namespace std;

#define MAXN 12

int N;
bool VR[MAXN]{}, VC[MAXN]{}, VD1[2*MAXN-1]{}, VD2[2*MAXN-1]{};

int sol(int i, int r, int c) {
    if (i == N) return 1;
    if (c == N) return 0;
    if (r == N) return 0;
    int res = sol(i, r, c+1);
    int d1 = r+c, d2 = (N-1-r)+c;
    if (!VR[r] && !VC[c] && !VD1[d1] && !VD2[d2]) {
        VR[r] = VC[c] = VD1[d1] = VD2[d2] = 1;
        res += sol(i+1, r+1, 0);
        VR[r] = VC[c] = VD1[d1] = VD2[d2] = 0;
    }
    return res;
}

int main() {
    cin >> N;
    cout << sol(0, 0, 0) << endl;
}