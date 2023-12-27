#include <bits/stdc++.h>
using namespace std;

#define MAXN 501

int N, s;
vector<int> A[MAXN];
bool V[MAXN][MAXN];

void dfs(int i) {
    if (V[s][i]) return;
    V[s][i] = true;
    for (int j: A[i]) {
        dfs(j);
    }
}

int main() {
    cin >> N;
    for (int i = 1; i <= N; ++i) {
        for (int j = 1; j <= N; ++j) {
            int X; cin >> X;
            A[i].push_back(X);
        }
        while (A[i].back() != i) A[i].pop_back();
    }
    for (s = 1; s <= N; ++s) {
        dfs(s);
    }
    for (int i = 1; i <= N; ++i) {
        for (int j: A[i]) {
            if (V[j][i]) {
                cout << j << endl;
                break;
            }
        }
    }
}