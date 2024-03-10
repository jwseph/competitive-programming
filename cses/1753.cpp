#include <bits/stdc++.h>
using namespace std;

const int MAXN = 2e6+50;

int N, K, P[MAXN];
string S, T, A;

int main() {
    cin >> S >> T;
    A = T+" "+S;
    N = A.size(), K = T.size();
    int res = 0;
    for (int i = 1; i < N; ++i) {
        int j = P[i-1];
        while (j && A[i] != A[j]) j = P[j-1];
        j += A[i] == A[j];
        P[i] = j;
        res += P[i] == K;
    }
    cout << res << endl;
}