#include <bits/stdc++.h>
using namespace std;

#define MAXN 102

int NT, N, M, E[MAXN];
string A[MAXN];
bool V[MAXN];
int vst;

bool check(int i, int v) {
    int ans = -1;
    for (int j = 0; j < M; ++j) {
        if (V[j]) continue;
        if (A[j][i]-'0' != v) continue;
        if (ans < 0) ans = E[j];
        if (ans != E[j]) return 0;
    }
    return ans >= 0;
}

void visit(int i, int v) {
    for (int j = 0; j < M; ++j) {
        if (V[j]) continue;
        if (A[j][i]-'0' != v) continue;
        V[j] = 1;
        ++vst;
    }
}

int main() {
    cin >> NT;
    while (NT--) {
        memset(V, 0, sizeof V);
        vst = 0;
        cin >> N >> M;
        for (int i = 0; i < M; ++i) {
            cin >> A[i] >> E[i];
        }
        bool res = 1;
        while (vst < M) {
            bool success = 0;
            int pv = vst;
            for (int i = 0; i < N && !success; ++i) {
                for (int v = 0; v < 2 && !success; ++v) {
                    if (check(i, v)) {
                        visit(i, v);
                        success = 1;
                    }
                }
            }
            if (pv == vst) {
                res = 0;
                break;
            }
        }
        cout << (res ? "OK" : "LIE") << endl;
    }
}