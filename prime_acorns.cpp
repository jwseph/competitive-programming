#include <bits/stdc++.h>
using namespace std;

int N;

bool prime(int X) {
    if (X <= 1) return false;
    for (int i = 2; i*i <= X; ++i) {
        if (X%i == 0) {
            return false;
        }
    }
    return true;
}

void dfs(int i, int res) {
    if (i > 0 && !prime(res)) return;
    if (i == N) {
        cout << res << endl;
        return;
    }
    for (int j = 1; j <= 9; ++j) {
        dfs(i+1, res*10+j);
    }
}

int main() {
    cin >> N;
    dfs(0, 0);
}