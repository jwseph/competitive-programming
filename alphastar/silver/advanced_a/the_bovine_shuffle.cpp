#include <bits/stdc++.h>
using namespace std;

#define MAXN 100'000

int N, A[MAXN], IN[MAXN]{};
queue<int> Q;

int main() {
    cin >> N;
    for (int i = 0; i < N; ++i) {
        cin >> A[i];
        --A[i];
        ++IN[A[i]];
    }
    for (int i = 0; i < N; ++i) {
        if (IN[i] == 0) {
            Q.push(i);
        }
    }
    while (Q.size()) {
        int i = Q.front();
        Q.pop();
        int j = A[i];
        if (--IN[j] == 0) {
            Q.push(j);
        }
    }
    int res = 0;
    for (int i = 0; i < N; ++i) {
        res += !!IN[i];
    }
    cout << res << endl;
}