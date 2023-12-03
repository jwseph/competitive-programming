#include <bits/stdc++.h>
using namespace std;

#define MAXN 16
#define ll long long

int N, I[1<<MAXN], A[1<<MAXN];
ll K;

int main() {
    memset(I, -1, sizeof I);
    cin >> N >> K;
    int n = 0;
    for (int i = 0; i < N; ++i) {
        int b; cin >> b;
        n = n<<1 | b;
    }
    I[n] = 0;
    A[0] = n;
    for (int k = 1; k <= K; ++k) {
        n ^= (n|(n&1)<<N)>>1;
        A[k] = n;
        if (I[n] >= 0) {
            K = I[n] + (K-I[n]) % (k-I[n]);
            break;
        }
        I[n] = k;
    }
    for (int i = N-1; i >= 0; --i) {
        cout << (A[K]>>i&1) << endl;
    }
}