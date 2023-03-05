#include <bits/stdc++.h>
using namespace std;

#define N_MAX 200'002

int N, K;
bool V[N_MAX];
queue<int> Q;

void add(int i) {
    if (i < 0 || i >= N_MAX || V[i]) return;
    V[i] = true;
    Q.push(i);
}

int main() {
    cin >> N >> K;
    memset(V, 0, sizeof V);
    add(N);
    for (int M = 0;; ++M) {
        for (int s = Q.size(); s > 0; --s) {
            int i = Q.front();
            Q.pop();
            if (i == K) {
                cout << M << endl;
                return 0;
            }
            add(i-1);
            add(i+1);
            add(2*i);
        }
    }
}