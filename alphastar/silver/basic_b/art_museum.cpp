#include <bits/stdc++.h>
using namespace std;

#define MAXN 10'000

int N, A[MAXN];

int sol(int i) {
    int l = i-1, r = i+1;
    while (l >= 0 && A[l] <= A[l+1]) {
        --l;
    }
    while (r < N && A[r] <= A[r-1]) {
        ++r;
    }
    return r-l-1;
}

int main() {
    cin >> N;
    for (int i = 0; i < N; ++i) {
        cin >> A[i];
    }
    int res = 0;
    for (int i = 0; i < N; ++i) {
        if (i > 0 && A[i-1] > A[i]) continue;
        if (i+1 < N && A[i+1] > A[i]) continue;
        res = max(res, sol(i));
    }
    cout << res << endl;
}