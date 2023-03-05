#include <bits/stdc++.h>
using namespace std;

int M, N;
char A[10];
string S;

void dfs(int i) {
    if (i == M) {
        if (S.size() == N) {
            cout << S << endl;
        }
        return;
    }
    if (S.size() < N) {
        S.push_back(A[i]);
        dfs(i+1);
        S.pop_back();
    }
    dfs(i+1);
}

int main() {
    cin >> M;
    for (int i = 0; i < M; ++i) {
        cin >> A[i];
    }
    cin >> N;
    dfs(0);
}