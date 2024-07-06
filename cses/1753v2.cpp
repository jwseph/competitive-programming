#include <bits/stdc++.h>
using namespace std;

vector<int> prefix(vector<int> A) {
    int N = A.size();
    vector<int> pi(N);
    for (int i = 1; i < N; ++i) {
        int j = pi[i-1];
        while (j && A[i] != A[j]) j = pi[j-1];
        j += A[i] == A[j];
        pi[i] = j;
    }
    return pi;
}

string st, pt;
vector<int> ar, pi;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin >> st >> pt;
    for (int c: pt) ar.push_back(c);
    ar.push_back(' ');
    for (int c: st) ar.push_back(c);
    pi = prefix(ar);
    int res = 0;
    for (int p: pi) {
        res += p == pt.size();
    }
    cout << res << endl;
}