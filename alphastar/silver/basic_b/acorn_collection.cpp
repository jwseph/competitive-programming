#include <bits/stdc++.h>
using namespace std;

int N, K, J = 0, P = 1;
vector<string> W[30];
vector<vector<string>> A;

vector<string> rep(int i) {
    vector<string> res;
    for (int j = 0, p = P; j < J; ++j) {
        p /= W[j].size();
        res.push_back(W[j][i/p]);
        i %= p;
    }
    return res;
}

int sol(int i) {
    vector<string> V = rep(i);
    int res = i+1;
    for (vector<string>& U: A) {
        if (U <= V) --res;
    }
    return res;
}

int main() {
    cin >> N >> K;
    for (int i = 0; i < N; ++i) {
        string S;
        for (int j = 0; j < 5; ++j) cin >> S;
        vector<string> V;
        for (int j = 0; S != "acorn."; ++j) {
            J = max(J, j+1);
            W[j].push_back(S);
            V.push_back(S);
            cin >> S;
        }
        A.push_back(V);
    }
    for (int j = 0; j < J; ++j) {
        vector<string>& w = W[j];
        sort(w.begin(), w.end());
        w.erase(unique(w.begin(), w.end()), w.end());
        P *= w.size();
    }
    int l = 0, r = P-1;
    while (l < r) {
        int h = (l+r)/2;
        if (K <= sol(h)) r = h;
        else l = h+1;
    }

    for (string& S: rep(l)) {
        cout << S << ' ';
    }
    cout << endl;
}