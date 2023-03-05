#include <bits/stdc++.h>
using namespace std;

#define N_MAX 3*100'000

int N, A[N_MAX];
stack<int> S;

int main() {
    cin >> N;
    for (int i = 0; i < N; ++i) {
        cin >> A[i];
    }
    long long res = 0;
    for (int j = 0; j < N; ++j) {
        while (!S.empty() && A[j] > A[S.top()]) {
            res += j-S.top()+1;
            S.pop();
        }
        if (!S.empty()) {
            res += j-S.top()+1;
        }
        S.push(j);
    }
    cout << res << endl;
}