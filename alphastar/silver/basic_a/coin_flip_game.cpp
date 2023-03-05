#include <bits/stdc++.h>
using namespace std;

int N, A[10];

void dfs(int i) {
    if (i == N) {
        for (int j = 0; j < N; ++j) {
            cout << A[j] << ' ';
        }
        cout << endl;
        return;
    }
    A[i] = 0;
    dfs(i+1);
    A[i] = 1;
    dfs(i+1);
}

int main() {
    cin >> N;
    dfs(0);
}