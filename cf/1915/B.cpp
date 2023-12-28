#include <bits/stdc++.h>
using namespace std;

int NT, N = 3;

string A[3];

int main() {
    cin >> NT;
    while (NT--) {
        for (int r = 0; r < 3; ++r) cin >> A[r];
        for (int r = 0; r < 3; ++r) {
            for (int c = 0; c < 3; ++c) {
                if (A[r][c] != '?') continue;
                int cnt[3]{};
                for (int i = 0; i < 3; ++i) if (i != r) {
                    cnt[A[i][c]-'A']++;
                }
                for (int j = 0; j < 3; ++j) if (j != c) {
                    cnt[A[r][j]-'A']++;
                }
                for (int i = 0; i < 3; ++i) {
                    if (cnt[i] == 0) {
                        cout << (char)('A'+i) << endl;
                    }
                }
            }
        }
    }
}