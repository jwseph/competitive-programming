#include <bits/stdc++.h>
using namespace std;

#define A_MAX 100'000'000

int N, A[20], res = 0;
bool V[20];

bool yay() {
    for (int d = 1; d <= A_MAX; d *= 10) {
        int t = 0;
        for (int i = 0; i < N; ++i) {
            t += V[i] * A[i]/d%10;
        }
        if (t > 9) return false;
    }
    return true;
}

void dfs(int i, int cnt) {
    if (i == N) {
        res = max(res, yay()*cnt);
        return;
    }
    V[i] = false;
    dfs(i+1, cnt);
    V[i] = true;
    dfs(i+1, cnt+1);
}

int main() {
    cin >> N;
    for (int i = 0; i < N; ++i) {
        cin >> A[i];
    }
    dfs(0, 0);
    cout << res << endl;
}