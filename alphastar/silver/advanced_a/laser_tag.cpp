#include <bits/stdc++.h>
using namespace std;

#define MAXN 100

int dr[4] = {-1, 1, 0, 0}, dc[4] = {0, 0, -1, 1};

int R, C;
char A[MAXN][MAXN];
bool V[MAXN][MAXN]{};
queue<int> Q;

int main() {
    cin >> C >> R;
    for (int r = 0; r < R; ++r) {
        for (int c = 0; c < C; ++c) {
            cin >> A[r][c];
            if (A[r][c] == 'C' && Q.empty()) {
                Q.push(r*C+c);
                V[r][c] = 1;
            }
        }
    }
    for (int res = -1;; ++res) {
        for (int qs = Q.size(); qs > 0; --qs) {
            int r = Q.front()/C, c = Q.front()%C;
            Q.pop();
            if (A[r][c] == 'C' && res >= 0) {
                cout << res << endl;
                return 0;
            }
            for (int d = 0; d < 4; ++d) {
                for (int i = r, j = c; 0 <= i && i < R && 0 <= j && j < C && A[i][j] != '*'; i += dr[d], j += dc[d]) {
                    if (V[i][j]) continue;
                    V[i][j] = 1;
                    Q.push(i*C+j);
                }
            }
        }
    }
}