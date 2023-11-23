#include <bits/stdc++.h>
using namespace std;

int N, Q;
vector<int> A[3];

int main() {
    cin >> N >> Q;
    for (int i = 0; i < N; ++i) {
        int t; cin >> t; --t;
        A[t].push_back(i);
    }
    while (Q--) {
        int i, j; cin >> i >> j; --i;
        for (int t = 0; t < 3; ++t) {
            auto l = lower_bound(begin(A[t]), end(A[t]), i);
            auto r = lower_bound(begin(A[t]), end(A[t]), j);
            cout << r-l << ' ';
        }
        cout << endl;
    }
}