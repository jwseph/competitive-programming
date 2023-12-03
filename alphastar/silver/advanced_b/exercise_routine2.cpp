#include <bits/stdc++.h>
using namespace std;

#define ll long long

int N;
ll K;

int main() {
    cin >> N >> K;
    K %= 1<<N;
    int n = 0;
    for (int i = 0; i < N; ++i) {
        int b; cin >> b;
        n = n<<1 | b;
    }
    while (K--) {
        n ^= (n|(n&1)<<N)>>1;
        cout << n << endl;
    }
    for (int i = N-1; i >= 0; --i) {
        cout << (n>>i&1) << endl;
    }
}