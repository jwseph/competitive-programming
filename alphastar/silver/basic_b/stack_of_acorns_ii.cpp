#include <bits/stdc++.h>
using namespace std;

#define MAXN 20

int N;
pair<int, int> A[MAXN];

int main() {
    cin >> N;
    for (int i = 0; i < N; ++i) {
        cin >> A[i].first >> A[i].second;
    }
    sort(A, A+N, greater<pair<int, int>>());
    int res = 0;
    for (int m = 0; m < (1<<N); ++m) {
        int cur = 0, w = INT_MAX, d = INT_MAX;
        for (int i = 0; i < N; ++i) {
            if (m&1<<i) {
                if (A[i].first >= w || A[i].second >= d) break;
                w = A[i].first;
                d = A[i].second;
                ++cur;
            }
        }
        res = max(res, cur);
    }
    cout << res << endl;
}