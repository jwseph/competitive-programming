#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e6+50;

int N, P[MAXN];
string A;

int main() {
    cin >> A;
    N = A.size();
    for (int i = 1; i < N; ++i) {
        int j = P[i-1];
        while (j && A[i] != A[j]) j = P[j-1];
        j += A[i] == A[j];
        P[i] = j;
    }

    vector<int> res;
    for (int j = P[N-1]; j; j = P[j-1]) {
        res.push_back(j);
    }
    reverse(begin(res), end(res));
    for (int a: res) cout << a << ' ';
    cout << endl;
}