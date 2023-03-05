#include <bits/stdc++.h>
using namespace std;

int N, A[10];
bool V[10];

void dfs(int i) {
    if (i == N) {
        int res = 0;
        for (int j = 0; j < N; ++j) {
            if (!V[j]) continue;
            res = res*10 + A[j];
        }
        if (res > 0) {
            cout << res << endl;
        }
        return;
    }
    V[i] = false;
    dfs(i+1);
    V[i] = true;
    dfs(i+1);
}

int main() {
    cin >> N;
    for (int i = 0; i < N; ++i) {
        cin >> A[i];
    }
    memset(V, 0, sizeof V);
    dfs(0);
}