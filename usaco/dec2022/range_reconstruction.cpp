#include <bits/stdc++.h>
using namespace std;

#define MAXN 302

int N, A[MAXN][MAXN], R[MAXN];

int main() {
    cin >> N;
    for (int i = 0; i < N; ++i) {
        for (int j = i; j < N; ++j) {
            cin >> A[i][j];
            A[j][i] = A[i][j];
        }
    }
    R[0] = 0;
    for (int i = 1; i < N; ++i) {
        int l = INT_MIN, r = INT_MAX;
        int mn = INT_MAX, mx = INT_MIN;
        unordered_set<int> cur;
        for (int j = i-1; j >= 0; --j) {
            mn = min(mn, R[j]);
            mx = max(mx, R[j]);
            if (mx-mn == A[i][j]) {
                l = max(l, mn);
                r = min(r, mx);
                continue;
            }
            if (mx-mn < A[i][j]) {
                int a = mx-A[i][j], b = mn+A[i][j];
                unordered_set<int> cur2;
                cur2.insert(a);
                cur2.insert(b);
                if (cur.size() && cur.find(a) == cur.end()) cur2.erase(a);
                if (cur.size() && cur.find(b) == cur.end()) cur2.erase(b);
                cur = cur2;
            }
        }
        R[i] = l;
        for (int x: cur) {
            if (l <= x && x <= r) R[i] = x;
        }
    }
    for (int i = 0; i < N; ++i) cout << R[i] << ' ';
    cout << endl;
}