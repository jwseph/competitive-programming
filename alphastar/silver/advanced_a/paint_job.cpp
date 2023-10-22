#include <bits/stdc++.h>
using namespace std;

#define MAXN 10'001

int S, E, N, P, A[MAXN];
bool V[MAXN]{};
queue<int> Q;

int main() {
    cin >> S >> E >> N >> P;
    for (int i = 0; i < N; ++i) {
        cin >> A[i];
    }
    V[S] = 1;
    Q.push(S);
    for (int res = 0; Q.size(); ++res)
    for (int s = Q.size(); s > 0; --s) {
        int i = Q.front(); Q.pop();
        if (i == E) {
            cout << res << endl;
            return 0;
        }
        for (int p = 0; p < N; ++p) {
            int j = A[p]*i%P;
            if (V[j]) continue;
            V[j] = 1;
            Q.push(j);
        }
    }
    cout << -1 << endl;
}