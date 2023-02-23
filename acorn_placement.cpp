#include <bits/stdc++.h>
using namespace std;

int N, Q, A[100'000];

int main() {
    cin >> N >> Q;
    for (int i = 0; i < N; ++i) {
        cin >> A[i];
    }
    sort(A, A+N);
    while (Q--) {
        int a, b; cin >> a >> b;
        cout << upper_bound(A, A+N, b)-lower_bound(A, A+N, a) << endl;
    }
}