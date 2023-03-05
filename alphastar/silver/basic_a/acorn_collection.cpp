// Problem: http://www.usaco.org/index.php?page=viewproblem2&cpid=342

#include <bits/stdc++.h>
using namespace std;

int N, K, J = 0, P = 1;
vector<string> W[30];  // at most 100 possible adj per slot
vector<vector<string>> A;

bool cmp(vector<string>& a, vector<string>& b) {  // <=
    for (int j = 0; j < J; ++j) {
        if (a[j] != b[j]) {
            return a[j] <= b[j];
        }
    }
    return true;
}

void get(int i, vector<string>& V) {
    for (int j = 0, p = P; j < J; ++j) {
        p /= W[j].size();
        V.push_back(W[j][i/p]);
        i %= p;
    }
}

int sol(int i) {
    // number of acorns before (exclusive) of index i
    vector<string> V;
    get(i, V);
    int res = i+1;
    for (vector<string>& U: A) {
        if (cmp(U, V)) --res;
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

    vector<string> V;
    get(l, V);
    for (string& S: V) {
        cout << S << ' ';
    }
    cout << endl;
}