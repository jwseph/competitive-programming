#include <bits/stdc++.h>
using namespace std;

#define N_MAX 100'000

int N, A[N_MAX], R[N_MAX];
stack<int> S;

int main() {
    cin >> N;
    for (int i = 0; i < N; ++i) {
        cin >> A[i];
    }
    for (int i = N-1; i >= 0; --i) {
        while (!S.empty() && A[i] >= A[S.top()]) {
            S.pop();
        }
        R[i] = S.empty() ? 0 : S.top()+1;
        S.push(i);
    }
    for (int i = 0; i < N; ++i) {
        cout << R[i] << endl;
    }
}