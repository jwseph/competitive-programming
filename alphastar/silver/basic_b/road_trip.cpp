#include <bits/stdc++.h>
using namespace std;

#define MAXT 1000002

int N, M, D[MAXT]{}, A = 0, B = 0;

int main() {
    cin >> N >> M;
    int t = 1;
    for (int i = 0; i < N; ++i) {
        int X; char C; cin >> X >> C;
        while (X--) {
            A += C == 'L' ? -1 : 1;
            D[t++] += A;
        }
    }
    while (t < MAXT) D[t++] += A;
    t = 1;
    for (int i = 0; i < M; ++i) {
        int X; char C; cin >> X >> C;
        while (X--) {
            B += C == 'L' ? -1 : 1;
            D[t++] -= B;
        }
    }
    while (t < MAXT) D[t++] -= B;
    int res = 0;
    for (t = 1; t < MAXT; ++t) {
        if (D[t] == 0 && D[t-1] != 0) {
            ++res;
        }
    }
    cout << res << endl;
}