#include <bits/stdc++.h>
using namespace std;

int N, res = 0;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin >> N;
    for (int i = 1; i <= N; ++i) res ^= i;
    for (int i = 0; i < N-1; ++i) {
        int x; cin >> x;
        res ^= x;
    }
    cout << res << endl;
}