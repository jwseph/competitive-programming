#include <bits/stdc++.h>
using namespace std;

#define N_MAX 100'001

int N, A[N_MAX];

int mn() {
    int res = N;
    for (int i = 0, j = 0; j < N;) {
        int Nw = A[j]-A[i]+1, Ns = j-i+1, cur = N-Ns;  // Ns is stones in window
        if (i < j && Nw > N) {
            ++i;
            continue;
        }
        if (N-Nw == 1 && N-Ns == 1) {
            ++cur;  // would've been illegal move
        }
        res = min(res, cur);
        ++j;
    }
    return res;
}

int mx() {
    int l = A[N-1]-A[1]-1-(N-3),
        r = A[N-2]-A[0]-1-(N-3);
    return max(l, r);
}

int main() {
    cin >> N;
    for (int i = 0; i < N; ++i) {
        cin >> A[i];
    }
    sort(A, A+N);
    cout << mn() << endl;
    cout << mx() << endl;
}