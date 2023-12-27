#include <bits/stdc++.h>
using namespace std;

#define MAXN 100005
#define MAXX 1000006

int N, D[MAXX]{};

int main() {
    D[1] = 1;
    for (int i = 2; i < MAXX; ++i) {
        if (D[i]) continue;
        for (int j = i; j < MAXX; j += i) {
            D[j] = i;
        }
    }
    cin >> N;
    while (N--) {
        int i; cin >> i;
        int res = 1;
        while (D[i] != 1) {
            int cur = 0;
            int d = D[i];
            while (i%d == 0) {
                i /= d;
                ++cur;
            }
            res *= cur+1;
        }
        cout << res << endl;
    }
}