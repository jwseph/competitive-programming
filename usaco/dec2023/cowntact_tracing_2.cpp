#include <bits/stdc++.h>
using namespace std;

int N;
string S;
vector<int> A;

int main() {
    cin >> N >> S;
    int cur = 0;
    for (int i = 0; i < N; ++i) {
        if (S[i] == '1') {
            ++cur;
            continue;
        }
        if (cur) {
            A.push_back(cur);
            cur = 0;
        }
    }
    if (cur) {
        A.push_back(cur);
        cur = 0;
    }
    int nights = INT_MAX;
    for (int ci = 0; ci < A.size(); ++ci) {
        if (ci == 0 && S[0] == '1') continue;
        if (ci == A.size()-1 && S.back() == '1') continue;
        nights = min(nights, (A[ci]-1)/2);
    }
    if (S[0] == '1') nights = min(nights, A[0]-1);
    if (S.back() == '1') nights = min(nights, A.back()-1);
    int res = 0;
    for (int c: A) {
        while (c > 0) {
            c -= 2*nights+1;
            ++res;
        }
    }
    cout << res << endl;
}