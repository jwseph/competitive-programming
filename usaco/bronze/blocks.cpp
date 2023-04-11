#include <bits/stdc++.h>
using namespace std;

#define MAXN 10
#define MAXM 4

int N, M = MAXM;
string S, B[MAXM], A[MAXN];
bool V[MAXM]{};
unordered_set<string> W;

void sol(int i, int n) {
    if (i == n) {
        W.insert(S);
        return;
    }
    for (int j = 0; j < M; ++j) {
        if (V[j]) continue;
        V[j] = true;
        for (int s = 0; s < 6; ++s) {
            S.push_back(B[j][s]);
            sol(i+1, n);
            S.pop_back();
        }
        V[j] = false;
    }
}

int main() {
    cin >> N;
    for (int i = 0; i < M; ++i) {
        cin >> B[i];
    }
    for (int i = 0; i < N; ++i) {
        cin >> A[i];
    }
    for (int m = 1; m <= M; ++m) {
        sol(0, m);
    }
    for (int i = 0; i < N; ++i) {
        cout << (W.count(A[i]) ? "YES" : "NO") << endl;
    }
}