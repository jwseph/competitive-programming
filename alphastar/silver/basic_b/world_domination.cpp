#include <bits/stdc++.h>
using namespace std;

#define MAXN 1000
#define pii pair<int, int>

int dr[4] = {-1, 1, 0, 0};
int dc[4] = {0, 0, -1, 1};

int N;
string A[MAXN];
bool V[MAXN][MAXN]{};

pii sol(int r, int c) {
    if (r < 0 || r >= N || c < 0 || c >= N || A[r][c] == '.') return {0, 1};
    if (V[r][c]) return {0, 0};
    V[r][c] = true;
    pii res = {1, 0};
    for (int d = 0; d < 4; ++d) {
        pii cur = sol(r+dr[d], c+dc[d]);
        res.first += cur.first;
        res.second += cur.second;
    }
    return res;
}

int main() {
    cin >> N;
    for (int r = 0; r < N; ++r) {
        cin >> A[r];
    }
    pii res = {0, INT_MAX};
    for (int r = 0; r < N; ++r) {
        for (int c = 0; c < N; ++c) {
            if (A[r][c] == '.' || V[r][c]) continue;
            pii cur = sol(r, c);
            if (cur.first > res.first || cur.first == res.first && cur.second < res.second) {
                res = cur;
            }
        }
    }
    cout << res.first << ' ' << res.second << endl;
}