#include <bits/stdc++.h>
using namespace std;

#define N_MAX 250

int N, A[N_MAX];
bool V[N_MAX]{};

int main() {
    cin >> N;
    for (int i = 0; i < N; ++i) {
        A[i] = i+1;
    }
    int i = 0, n = A[0];
    V[0] = true;
    for (;;) {
        i = (i+n)%N;
        if (V[A[i]-1]) break;
        V[n-1] = true;
        swap(n, A[i]);
    }
    cout << n << endl;
}