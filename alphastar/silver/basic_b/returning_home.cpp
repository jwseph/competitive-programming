#include <bits/stdc++.h>
using namespace std;

#define N_MAX 5001

int R, N, H, A[N_MAX][2];
stack<int> res;

bool dfs(int i) {
    if (i == H) {
        res.push(i);
        return true;
    }
    if (A[i][0] < 0) {
        return false;
    }
    for (int &j: A[i]) {
        if (dfs(j)) {
            res.push(i);
            return true;
        }
    }
    return false;
}

int main() {
    cin >> R >> N >> H;
    memset(A, -1, sizeof A);
    for (int i = 0; i < N; ++i) {
        int j; cin >> j;
        cin >> A[j][0] >> A[j][1];
    }
    dfs(1);
    cout << res.size() << endl;
    while (!res.empty()) {
        cout << res.top() << endl;
        res.pop();
    }
}