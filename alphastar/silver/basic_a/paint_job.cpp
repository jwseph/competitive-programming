#include <bits/stdc++.h>
using namespace std;

int A, B, N, P, X[10000];
bool V[10001];
queue<int> Q;

int main() {
    cin >> A >> B >> N >> P;
    memset(V, 0, sizeof V);
    for (int i = 0; i < N; ++i) {
        cin >> X[i];
    }
    Q.push(A);
    V[A] = true;
    for (int M = 0; !Q.empty(); ++M) {
        for (int s = Q.size(); s > 0; --s) {
            int i = Q.front();
            Q.pop();
            if (i == B) {
                cout << M << endl;
                return 0;
            }
            for (int j = 0; j < N; ++j) {
                int k = (i*X[j])%P;
                if (V[k]) continue;
                V[k] = true;
                Q.push(k);
            }
        }
    }
    cout << -1 << endl;
}