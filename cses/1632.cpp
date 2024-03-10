#include <bits/stdc++.h>
using namespace std;

const int MAXN = 2e5+5;

int N, K;
array<int, 2> A[MAXN];
multiset<int> S;

int main() {
    cin >> N >> K;
    for (int i = 0; i < N; ++i) {
        cin >> A[i][1] >> A[i][0];
    }
    while (K--) S.insert(0);
    sort(A, A+N);
    int res = 0;
    for (int i = 0; i < N; ++i) {
        auto [r, l] = A[i];
        auto it = S.upper_bound(l);
        if (it == S.begin()) continue;
        S.erase(--it);
        S.insert(r);
        ++res;
    }
    cout << res << endl;
}