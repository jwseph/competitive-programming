// Problem: http://www.usaco.org/index.php?page=viewproblem2&cpid=858

#include <bits/stdc++.h>
using namespace std;

int N, M, C, A[100'000], mA = INT_MAX, MA = INT_MIN;

bool sol(int W) {
    int i = 0, m = 0;
    while (i < N && m < M) {
        int j = upper_bound(A, A+N, A[i]+W)-A;
        i = min(j, i+C);
        ++m;
    }
    return i >= N;
}

int main() {
    cin >> N >> M >> C;
    for (int i = 0; i < N; ++i) {
        cin >> A[i];
        mA = min(mA, A[i]);
        MA = max(MA, A[i]);
    }
    sort(A, A+N);
    int l = 0, r = MA-mA;
    while (l < r) {  // lower bound of W
        int h = (l+r)/2;
        if (sol(h)) r = h;
        else l = h+1;
    }
    cout << l << endl;
}