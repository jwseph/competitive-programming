#include <bits/stdc++.h>
using namespace std;

#define MAXN 500

int N, M, res = 0;
string A[MAXN], B[MAXN];
vector<int> idx;

void sol(int i) {
    if (i == M) {
        if (idx.size() < 3) return;
        unordered_set<string> u;
        for (int a = 0; a < N; ++a) {
            string s;
            for (int i: idx) s += A[a][i];
            u.insert(s);
        }
        for (int b = 0; b < N; ++b) {
            string s;
            for (int i: idx) s += B[b][i];
            if (u.count(s)) return;
        }
        ++res;
        return;
    }
    if (idx.size() < 3) {
        idx.push_back(i);
        sol(i+1);
        idx.pop_back();
    }
    sol(i+1);
}

int main() {
    cin >> N >> M;
    for (int i = 0; i < N; ++i) {
        cin >> A[i];
    }
    for (int i = 0; i < N; ++i) {
        cin >> B[i];
    }
    sol(0);
    cout << res << endl;
}