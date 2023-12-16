#include <bits/stdc++.h>
using namespace std;

#define MAXN 202

int N, X[MAXN], Y[MAXN], P[MAXN];
bool V[MAXN];

int dfs(int i) {
    if (V[i]) return 0;
    V[i] = 1;
    int res = 1;
    for (int j = 0; j < N; ++j) {
        int x = X[i]-X[j], y = Y[i]-Y[j];
        if (x*x+y*y <= P[i]*P[i]) {
            res += dfs(j);
        }
    }
    return res;
}

int main() {
    cin >> N;
    for (int i = 0; i < N; ++i) {
        cin >> X[i] >> Y[i] >> P[i];
    }
    int res = 0;
    for (int i = 0; i < N; ++i) {
        memset(V, 0, sizeof V);
        res = max(res, dfs(i));
    }
    cout << res << endl;
}