#include <bits/stdc++.h>
using namespace std;

#define MAXN 1000
#define MAXK 100

int K, N, M, C[MAXN], F[MAXK];
bool V[MAXN];
vector<int> A[MAXN];
queue<int> Q;

int main() {
    cin >> K >> N >> M;
    for (int k = 0; k < K; ++k) {
        cin >> F[k]; --F[k];
    }
    while (M--) {
        int i, j; cin >> i >> j; --i; --j;
        A[i].push_back(j);
    }
    for (int k = 0; k < K; ++k) {
        memset(V, 0, sizeof V);
        Q.push(F[k]);
        V[F[k]] = 1;
        while (Q.size()) {
            int i = Q.front();
            Q.pop();
            ++C[i];
            for (int j: A[i]) {
                if (V[j]) continue;
                V[j] = 1;
                Q.push(j);
            }
        }
    }
    int res = 0;
    for (int i = 0; i < N; ++i) {
        res += C[i] == K;
    }
    cout << res << endl;
}