#include <bits/stdc++.h>
using namespace std;

int R, C;
vector<string> A;
vector<int> rows, cols;
vector<pair<int, int>> V;

int main() {
    ifstream cin("aoc/23/11.in");
    string S;
    while (cin >> S) A.push_back(S);
    R = A.size(), C = A[0].size();
    for (int r = 0; r < R; ++r) {
        int cur = 0;
        for (int c = 0; c < C; ++c) {
            cur += A[r][c] == '#';
            if (A[r][c] == '#') V.push_back({r, c});
        }
        if (cur == 0) rows.push_back(r);
    }
    for (int c = 0; c < C; ++c) {
        int cur = 0;
        for (int r = 0; r < R; ++r) {
            cur += A[r][c] == '#';
        }
        if (cur == 0) cols.push_back(c);
    }
    int res = 0;
    for (int i = 0; i < V.size(); ++i) {
        for (int j = i+1; j < V.size(); ++j) {
            auto [r1, c1] = V[i];
            auto [r2, c2] = V[j];
            if (r2 < r1) swap(r1, r2);
            if (c2 < c1) swap(c1, c2);
            int dr = r2-r1 + upper_bound(begin(rows), end(rows), r2) - lower_bound(begin(rows), end(rows), r1);
            int dc = c2-c1 + upper_bound(begin(cols), end(cols), c2) - lower_bound(begin(cols), end(cols), c1);
            // cout << dr << ' ' << dc << endl;
            int cur = dr+dc;
            res += cur;
        }
    }
    cout << res << endl;
}