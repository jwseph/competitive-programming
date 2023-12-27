#include <bits/stdc++.h>
using namespace std;

#define MAXA 5000006

bool C[MAXA]{};
int P[4][175000];
int sz[4]{};

int NT, N;

int main() {
    for (int i = 2; i*i <= MAXA; ++i) {
        if (C[i]) continue;
        for (int j = i*i; j <= MAXA; j += i) {
            C[j] = 1;
        }
    }
    P[1][sz[1]++] = 1;
    for (int i = 2; i <= MAXA; ++i) {
        if (C[i]) continue;
        P[i%4][sz[i%4]++] = i;
    }

    cin >> NT;
    while (NT--) {
        cin >> N;
        int res = INT_MAX, res_i = -1;
        for (int i = 0; i < N; ++i) {
            int cur; cin >> cur;
            if (cur%4 == 0) {
                cur /= 4;
                if (cur < res) {
                    res = cur;
                    res_i = 1;
                }
                continue;
            }
            int r = cur%4;
            int j = upper_bound(P[r], P[r]+sz[r], cur) - P[r];
            int p = P[r][j-1];
            cur -= p;
            cur /= 4;
            if (cur < res) {
                res = cur;
                res_i = 0;
            }
        }
        cout << (res_i == 0 ? "Farmer John" : "Farmer Nhoj") << endl;
    }
}