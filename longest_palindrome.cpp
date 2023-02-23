#include <bits/stdc++.h>
using namespace std;

int N;
string S;

void read() {
    while (!cin.eof()) {
        string s;
        getline(cin, s);
        S += s+"\n";
    }
    N = S.size();
}

int main() {
    read();
    int res = 0, L = 0, R = 0;
    // Odd-length
    for (int i = 0; i < N; ++i) {
        if (!isalpha(S[i])) continue;
        int l = i, r = i, cur = -1;
        while (0 <= l && r < N && tolower(S[l]) == tolower(S[r])) {
            cur += 2;
            if (res < cur) {
                res = cur;
                L = l;
                R = r+1;
            }
            --l; ++r;
            while (0 <= l && !isalpha(S[l])) --l;
            while (r < N && !isalpha(S[r])) ++r;
        }
    }
    // Even-length
    for (int i = 0; i < N; ++i) {
        int l = i, r = i+1, cur = 0;
        while (0 <= l && !isalpha(S[l])) --l;
        while (r < N && !isalpha(S[r])) ++r;
        while (0 <= l && r < N && tolower(S[l]) == tolower(S[r])) {
            cur += 2;
            if (res < cur) {
                res = cur;
                L = l;
                R = r+1;
            }
            --l; ++r;
            while (0 <= l && !isalpha(S[l])) --l;
            while (r < N && !isalpha(S[r])) ++r;
        }
    }
    cout << res << endl;
    cout << S.substr(L, R-L) << endl;
}