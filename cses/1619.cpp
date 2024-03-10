#include <bits/stdc++.h>
using namespace std;

const int MAXN = 2e5+5;

int N;
pair<int, int> A[2*MAXN];

int main() {
    cin >> N; N *= 2;
    for (int i = 0; i < N; i += 2) {
        int a, b; cin >> a >> b;
        A[i] = {a, 1};
        A[i+1] = {b, -1};
    }
    sort(A, A+N);
    int res = 0, cur = 0;
    for (int i = 0; i < N; ++i) {
        cur += A[i].second;
        res = max(res, cur);
    }
    cout << res << endl;
}