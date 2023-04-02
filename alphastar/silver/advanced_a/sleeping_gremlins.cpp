#include <bits/stdc++.h>
using namespace std;

#define MAXN 100'000

int N, K, B, A[MAXN+1]{};

int main() {
    cin >> N >> K >> B;
    for (int b = 0; b < B; ++b) {
        int i; cin >> i;
        A[i] = 1;
    }
    for (int i = 1; i <= N; ++i) {
        A[i] += A[i-1];
    }
    int res = INT_MAX;
    for (int i = 0; i+K <= N; ++i) {
        res = min(res, A[i+K]-A[i]);
    }
    cout << res << endl;
}