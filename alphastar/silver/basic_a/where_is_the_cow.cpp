#include <bits/stdc++.h>
using namespace std;

#define MOD 1000000007

int N;
string S;

int main() {
    cin >> S;
    N = S.size();
    long long res = 1, fact = 1;
    for (int i = 0; i < N; ++i) {
        int cnt = 0;
        for (int j = N-i; j < N; ++j) {
            if (S[j] < S[N-1-i]) ++cnt;
        }
        // cout << fact << " * " << cnt << endl;
        res = (res+(fact*cnt)%MOD)%MOD;  // No. of perms before S
        fact = fact*(i+1)%MOD;
    }
    cout << res << endl;
}