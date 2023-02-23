#include <bits/stdc++.h>
using namespace std;

int N, K, R, A[50'000];

bool sol() {
    int i = 0;
    for (int k = K; k > 0 && i < N; --k) {
        i = upper_bound(A, A+N, A[i]+2*R)-A;
    }
    return i >= N;
}

int main() {
    cin >> N >> K;
    for (int i = 0; i < N; ++i) {
        cin >> A[i];
    }
    sort(A, A+N);
    for (R = 0; !sol(); ++R);
    cout << R << endl;
}