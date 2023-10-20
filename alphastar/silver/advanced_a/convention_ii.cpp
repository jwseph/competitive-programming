#include <bits/stdc++.h>
using namespace std;

#define MAXN 100'000

int N, A[MAXN], T[MAXN], C[MAXN];
priority_queue<int, vector<int>, greater<int>> Q;

bool cmp(int i, int j) {
    if (A[i] != A[j]) return A[i] < A[j];
    return i < j;
}

int main() {
    cin >> N;
    for (int i = 0; i < N; ++i) {
        cin >> A[i] >> T[i];
        C[i] = i;
    }
    sort(C, C+N, cmp);
    int c = 0, res = 0, t;
    while (c < N || Q.size()) {
        if (Q.empty()) {
            t = A[C[c]];
            Q.push(C[c++]);
        }
        int i = Q.top();
        res = max(res, t-A[i]);
        t += T[i];
        Q.pop();
        while (c < N && A[C[c]] <= t) Q.push(C[c++]);
    }
    cout << res << endl;
}