#include <bits/stdc++.h>
using namespace std;

const int MAXN = 2e5+5;

int N;
pair<int, int> A[MAXN];

int main() {
    cin >> N;
    for (int i = 0; i < N; ++i) {
        cin >> A[i].first >> A[i].second;
    }
    sort(A, A+N);
    int res = 0, t = INT_MAX;
    for (int i = N-1; i >= 0; --i) {
        auto [a, b] = A[i];
        if (b <= t) {
            t = a;
            ++res;
        }
    }
    cout << res << endl;
}