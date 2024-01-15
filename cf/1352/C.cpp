#include <bits/stdc++.h>
using namespace std;

int NT, N, K;

int sol(int k) {
    if (k+1 < N) return k+1;
    if (k+1 == N) return k+2;
    int w = k/N;
    return N*w + sol(k-(N-1)*w);
}

int main() {
    cin >> NT;
    while (NT--) {
        cin >> N >> K; --K;
        cout << sol(K) << endl;
    }
}