#include <bits/stdc++.h>
using namespace std;

#define MAXN 20

int N, A[MAXN], tot = 0;
bool V[MAXN]{};

bool check(int i, int a, int b, int c) {
    if (a > c || b > c || c*3 < tot) return 0;
    if (i == N) return 1;
    if (V[i]) return check(i+1, a, b, c);
    return check(i+1, a+A[i], b, c) || check(i+1, a, b+A[i], c);
}

int dfs(int i, int cur) {
    if (i == N) {
        return check(0, 0, 0, cur) ? cur : 2000;
    }
    int res = dfs(i+1, cur);
    V[i] = 1;
    res = min(res, dfs(i+1, cur+A[i]));
    V[i] = 0;
    return res;
}

int main() {
    cin >> N;
    for (int i = 0; i < N; ++i) {
        cin >> A[i];
        tot += A[i];
    }
    sort(A, A+N);
    cout << dfs(0, 0) << endl;
}