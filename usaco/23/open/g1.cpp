#include <bits/stdc++.h>
using namespace std;

#define MAXN 100005

int NT;

string sol() {
    int N, M; cin >> N >> M;
    int C[N], S[N], F[N];
    for (int i = 0; i < N; ++i) cin >> C[i];
    for (int i = 0; i < N; ++i) cin >> S[i];
    for (int i = 0; i < N; ++i) cin >> F[i];
    vector<int> A[N];
    for (int e = 0; e < M; ++e) {
        int i, j; cin >> i >> j; --i; --j;
        A[i].push_back(j);
        A[j].push_back(i);
    }

    int V[N]; memset(V, 0, sizeof V);
    bool K[N+1]; memset(K, 0, sizeof K);
    vector<int> W[N+1];

    queue<int> Q;
    V[0] = 2;
    Q.push(0);
    while (Q.size()) {
        int i = Q.front(); Q.pop();
        K[S[i]] = 1;
        for (int j: W[S[i]]) {
            V[j] = 2;
            Q.push(j);
        }
        W[S[i]] = {};

        for (int j: A[i]) {
            if (V[j]) continue;
            if (K[C[j]]) {
                V[j] = 2;
                Q.push(j);
                continue;
            }
            V[j] = 1;
            W[C[j]].push_back(j);
        }
    }

    int V2[N]; memset(V2, 0, sizeof V2);
    memset(K, 0, sizeof K);
    for (int i = 0; i < N+1; ++i) W[i] = {};

    Q = {};
    V2[0] = 2;
    Q.push(0);
    while (Q.size()) {
        int i = Q.front(); Q.pop();
        K[F[i]] = 1;
        for (int j: W[F[i]]) {
            V2[j] = 2;
            Q.push(j);
        }
        W[F[i]] = {};

        for (int j: A[i]) {
            if (V2[j] || V[j] < 2) continue;
            if (K[C[j]] || F[j] == C[j]) {  // F[j] == C[j] because we need C[j] to be able to exit
                V2[j] = 2;
                Q.push(j);
                continue;
            }
            V2[j] = 1;
            W[C[j]].push_back(j);
        }
    }

    for (int i = 0; i < N; ++i) {
        if (V[i] != 2) {
            if (S[i] != F[i]) return "NO";
            continue;
        }
        if (V2[i] != 2) return "NO";
    }
    return "YES";
}

int main() {
    cin >> NT;
    while (NT--) {
        cout << sol() << endl;
    }
}