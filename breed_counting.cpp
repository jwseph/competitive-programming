#include <bits/stdc++.h>
using namespace std;

#define N_MAX 100'000

int N, Q, A[N_MAX][3];

int main() {
    cin >> N >> Q;
    for (int i = 1; i <= N; ++i) {
        for (int T = 0; T < 3; ++T) {
            A[i][T] = A[i-1][T];
        }
        int T; cin >> T; --T;
        ++A[i][T];
    }
    while (Q--) {
        int a, b; cin >> a >> b;
        for (int T = 0; T < 3; ++T) {
            cout << A[b][T]-A[a-1][T] << ' ';
        }
        cout << endl;
    }
}