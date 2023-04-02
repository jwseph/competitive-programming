#include <bits/stdc++.h>
using namespace std;

#define MAXN 100'000

int N, M, C, A[MAXN];

bool sol(int W) {
    int t = INT_MIN, i, c, m = 0;
    for (i = 0; i < N && m <= M; ++i) {
        if (A[i] > t+W || c == 0) {
            t = A[i];
            c = C;
            ++m;
        }
        --c;
    }
    return i == N;
}

int main() {
    cin >> N >> M >> C;
    for (int i = 0; i < N; ++i) {
        cin >> A[i];
    }
    sort(A, A+N);
    int l = 0, r = 1'000'000'000;
    while (l < r) {
        int h = (l+r)/2;
        if (sol(h)) r = h;
        else l = h+1;
    }
    cout << l << endl;  
}