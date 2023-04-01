#include <bits/stdc++.h>
using namespace std;

#define MAXN 100'000

int N, M, K, T[MAXN], A[MAXN];

int main() {
    cin >> N >> M >> K;
    for (int i = 0; i < N; ++i) {
        T[i] = i;
    }
    for (int i = 0; i < M; ++i) {
        int L, R; cin >> L >> R;
        reverse(T+L-1, T+R);
    }
    memset(A, -1, sizeof A);
    for (int i = 0; i < N; ++i) {
        if (A[i] >= 0) continue;
        vector<int> V = {i};
        int j = T[i];
        while (j != i) {
            V.push_back(j);
            j = T[j];
        }
        for (int j = 0; j < V.size(); ++j) {
            A[V[j]] = V[(K+j)%V.size()]+1;
        }
    }
    for (int i = 0; i < N; ++i) {
        cout << A[i] << endl;
    }
}