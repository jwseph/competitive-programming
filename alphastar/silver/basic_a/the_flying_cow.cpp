#include <bits/stdc++.h>
using namespace std;

#define N_MAX 1'000'100

int N, M;
bool V[N_MAX];
queue<int> Q;

int main() {
    cin >> N;
    memset(V, 0, sizeof V);
    Q.push(1);
    for (M = 0;; ++M) {
        for (int s = Q.size(); s > 0; --s) {
            int i = Q.front();
            Q.pop();
            if (i < 0 || i >= N_MAX || V[i]) continue;
            V[i] = true;
            if (i == N) {
                cout << M << endl;
                return 0;
            }
            Q.push(i-1);
            Q.push(i+1);
            Q.push(3*i);
        }
    }
}