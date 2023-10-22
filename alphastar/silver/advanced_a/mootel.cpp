#include <bits/stdc++.h>
using namespace std;

#define MAXN 100

int N, M;
bool A[MAXN][MAXN], V[MAXN]{};
queue<int> Q;

int main() {
    cin >> N >> M; --M;
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            cin >> A[i][j];
        }
    }
    V[M] = 1;
    Q.push(M);
    while (Q.size()) {
        vector<int> cur;
        for (int q = Q.size(); q > 0; --q) {
            int i = Q.front(); Q.pop();
            cur.push_back(i+1);
            for (int j = 0; j < N; ++j) {
                if (!A[i][j] || V[j]) continue;
                V[j] = 1;
                Q.push(j);
            }
        }
        sort(begin(cur), end(cur));
        for (int i: cur) cout << i << ' ';
        cout << endl;
    }
}