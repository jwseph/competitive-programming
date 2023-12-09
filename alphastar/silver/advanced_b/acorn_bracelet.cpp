#include <bits/stdc++.h>
using namespace std;

#define MAXN 100005

int N;
string A;
int L[MAXN], R[MAXN];

int main() {
    cin >> A;
    N = A.size();
    L[0] = 0;
    for (int i = 0; i < N; ++i) {
        if (L[i] == -1) {
            L[i+1] = -1;
            continue;
        }
        L[i+1] = L[i] + (A[i] == '(' ? 1 : -1);
    }
    R[N] = 0;
    for (int i = N-1; i >= 0; --i) {
        if (R[i+1] == -1) {
            R[i] = -1;
            continue;
        }
        R[i] = R[i+1] + (A[i] == ')' ? 1 : -1);
    }
    int res = 0;
    for (int i = 0; i < N; ++i) {
        if (L[i] < 0 || R[i+1] < 0) continue;
        int cur = L[i] - R[i+1];
        cur += A[i] == ')' ? 1 : -1;
        if (cur == 0) ++res;
    }
    cout << res << endl;
}