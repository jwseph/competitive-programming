#include <bits/stdc++.h>
using namespace std;

#define MAXN 100005

int NT, N, K;
string S;

int main() {
    cin >> NT;
    while (NT--) {
        cin >> N >> K >> S;
        string R(N, '.');
        int idx[2] = {-MAXN, -MAXN};
        int res = 0;
        for (int i = 0; i < N; ++i) {
            int j = S[i]-'G';
            if (abs(i-idx[j]) > K) {
                idx[j] = min(i+K, N-1);
                if (R[idx[j]] != '.') --idx[j];
                R[idx[j]] = S[i];
                ++res;
            }
        }
        cout << res << endl;
        cout << R << endl;
    }
}