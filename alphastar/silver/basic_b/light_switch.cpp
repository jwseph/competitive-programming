    #include <bits/stdc++.h>
    using namespace std;

    int N = 20, I = 0;

    int main() {
        for (int i = 0; i < N; ++i) {
            int S; cin >> S;
            I = I<<1 | S;
        }
        int res = INT_MAX;
        for (int m = 0; m < (1<<N); ++m) {
            int cur = 0, s = I;
            for (int i = 0; i < N; ++i) {
                if (m&1<<i) {
                    if (i > 0) s ^= 0b111 << (i-1);
                    else s ^= 0b11;
                    ++cur;
                }
            }
            if ((s & (1<<N)-1) == 0) res = min(res, cur);
        }
        cout << res << endl;
    }