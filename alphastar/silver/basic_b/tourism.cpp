#include <bits/stdc++.h>
using namespace std;

#define MAXN 100'000

int N, A[MAXN][2];

int dis(int i, int j) {
    return abs(A[i][0] - A[j][0]) + abs(A[i][1] - A[j][1]);
}

int main() {
    cin >> N;
    for (int i = 0; i < N; ++i) {
        cin >> A[i][0] >> A[i][1];
    }
    int all = 0, res = 0;
    for (int i = 1; i < N; ++i) {
        all += dis(i-1, i);
    }
    for (int i = 1; i < N-1; ++i) {
        int cur = dis(i, i-1) + dis(i, i+1) - dis(i-1, i+1);
        res = max(res, cur);
    }
    cout << all-res << endl;
}