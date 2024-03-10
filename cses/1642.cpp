#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e3+5;

int N, K, A[MAXN];
set<array<int, 3>> S;

int main() {
    cin >> N >> K;
    for (int i = 0; i < N; ++i) cin >> A[i];
    for (int i = 0; i < N; ++i) {
        for (int j = i+1; j < N; ++j) {
            S.insert({A[i]+A[j], i, j});
        }
    }
    for (int i = 0; i < N; ++i) {
        for (int j = i+1; j < N; ++j) {
            S.erase({A[i]+A[j], i, j});
        }
        for (int j = 0; j < i; ++j) {
            int cur = K-A[j]-A[i];
            auto it = S.lower_bound({cur, 0, 0});
            if (it != S.end() && (*it)[0] == cur) {
                auto [_, l, r] = *it;
                cout << j+1 << ' ' << i+1 << ' ' << l+1 << ' ' << r+1 << endl;
                return 0;
            }
        }
    }
    cout << "IMPOSSIBLE" << endl;
}