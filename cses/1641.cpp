#include <bits/stdc++.h>
using namespace std;

const int MAXN = 5e3+5;

int N, K, A[MAXN];
map<int, int> V;

int main() {
    cin >> N >> K;
    for (int i = 0; i < N; ++i) cin >> A[i];
    for (int i = 0; i < N; ++i) {
        for (int j = i+1; j < N; ++j) {
            int cur = K-A[i]-A[j];
            if (V.count(cur)) {
                cout << V[cur]+1 << ' ' << i+1 << ' ' << j+1 << endl;
                return 0;
            }
        }
        V[A[i]] = i;
    }
    cout << "IMPOSSIBLE" << endl;
}