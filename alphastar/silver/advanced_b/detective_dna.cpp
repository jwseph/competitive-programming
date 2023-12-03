#include <bits/stdc++.h>
using namespace std;

#define MAXN 7

int N;
string S, A[MAXN];
bool V[MAXN]{};

void merge(string T) {
    int N = S.size();
    for (int w = min(7, N); w >= 0; --w) {
        if (S.substr(N-w, w) == T.substr(0, w)) {
            while (w--) S.pop_back();
            break;
        }
    }
    S += T;
}

int dfs(int n) {
    if (n == 0) return S.size();
    int res = INT_MAX;
    for (int i = 0; i < N; ++i) {
        if (V[i]) continue;
        V[i] = 1;
        string T = S;
        merge(A[i]);
        res =  min(res, dfs(n-1));
        S = T;
        V[i] = 0;
    }
    return res;
}

int main() {
    cin >> N;
    for (int i = 0; i < N; ++i) {
        cin >> A[i];
    }
    cout << dfs(N) << endl;
}