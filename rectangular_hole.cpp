#include <bits/stdc++.h>
using namespace std;

int N, B, A[20];

int dfs(int i, int S) {
    if (S >= B) return S;
    if (i == N) return INT_MAX;
    return min(dfs(i+1, S), dfs(i+1, S+A[i]));
}

int main() {
    cin >> N >> B;
    for (int i = 0; i < N; ++i) {
        cin >> A[i];
    }
    sort(A, A+N);
    cout << dfs(0, 0)-B << endl;
}