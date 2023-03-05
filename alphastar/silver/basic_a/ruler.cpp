#include <bits/stdc++.h>
using namespace std;

void dfs(int N) {
    if (N == 0) return;
    dfs(N-1);
    cout << string(N, '*') << endl;
    dfs(N-1);
}

int main() {
    int N; cin >> N;
    cout << string(N, '*') << endl;
    dfs(N-1);
    cout << string(N, '*') << endl;
}