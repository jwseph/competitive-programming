#include <bits/stdc++.h>
using namespace std;

#define MAXN 100'000

int N;
pair<int, int> A[MAXN];

int main() {
    cin >> N >> N;
    for (int i = 0; i < N; ++i) {
        int a, b; cin >> a >> b;
        if (a > b) swap(a, b);
        A[i] = {b, a};
    }
    sort(A, A+N);
    int res = 2, cur = A[0].first;
    for (int i = 1; i < N; ++i) {
        auto [b, a] = A[i];
        if (a < cur) continue;
        ++res;
        cur = b;
    }
    cout << res << endl;
}