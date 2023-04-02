#include <bits/stdc++.h>
using namespace std;

#define MAXN 50'000

int N, K, A[MAXN];

bool sol(int R) {
    int i = 0;
    for (int k = 0; k < K && i < N; ++k) {
        i = upper_bound(A, A+N, A[i]+2*R) - A;
    }
    return i == N;
}

int main() {
    cin >> N >> K;
    for (int i = 0; i < N; ++i) {
        cin >> A[i];
    }
    sort(A, A+N);
    int l = 0, r = 500'000'000;
    while (l < r) {
        int h = (l+r)/2;
        if (sol(h)) r = h;
        else l = h+1;
    }
    cout << l << endl;
}