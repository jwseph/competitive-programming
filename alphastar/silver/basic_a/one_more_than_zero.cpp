#include <bits/stdc++.h>
using namespace std;

int N, T = 0;
string S;

void dfs(int cnt) {
    if (S.size() == N) {
        if (cnt > S.size()-cnt) {
            cout << S << endl;
            ++T;
        }
        return;
    }
    S.push_back('0');
    dfs(cnt);
    S.back() = '1';
    dfs(cnt+1);
    S.pop_back();
}

int main() {
    cin >> N;
    dfs(0);
    cout << T << endl;
}