#include <bits/stdc++.h>
using namespace std;

#define N_MAX 100

int N, A[N_MAX], B[N_MAX];
bool V[N_MAX]{};

int sol(int i) {
    int len = 0;
    while (!V[i]) {
        V[i] = true;
        i = B[A[i]];
        ++len;
    }
    return len;
}

int main() {
    cin >> N;
    for (int i = 0; i < N; ++i) {
        cin >> A[i]; --A[i];
    }
    for (int i = 0; i < N; ++i) {
        int j; cin >> j; --j;
        B[j] = i;
    }
    int res = 0, len = -1;
    for (int i = 0; i < N; ++i) {
        if (!V[i] && i != B[A[i]]) {  // length 1 cycles don't count
            ++res;
            len = max(len, sol(i));
        }
    }
    cout << res << ' ' << len << endl;
}