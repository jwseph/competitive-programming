#include <bits/stdc++.h>
using namespace std;

#define MAXN 20

int N, B, A[MAXN];

int main() {
    cin >> N >> B;
    for (int i = 0; i < N; ++i) {
        cin >> A[i];
    }
    int res = INT_MAX;
    for (int m = 0; m < (1<<N); ++m) {
        int h = 0;
        for (int i = 0; i < N; ++i) {
            if (m&1<<i) h += A[i];
        }
        if (h >= B && h < res) {
            res = h;
        }
    }
    cout << res-B << endl;
}