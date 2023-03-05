#include <bits/stdc++.h>
using namespace std;

int W, N;
vector<string> A;
unordered_map<string, int> I;

int main() {
    cin >> W >> N;
    for (int i = 0; i < W; ++i) {
        string S; cin >> S;
        A.push_back(S);
        I[S] = i+1;
    }
    sort(A.begin(), A.end());
    while (N--) {
        int K; string P; cin >> K >> P;
        int i = lower_bound(A.begin(), A.end(), P)-A.begin() + K-1;
        if (0 <= i && i < W && A[i].compare(0, P.size(), P) == 0) {
            cout << I[A[i]] << endl;
        } else {
            cout << -1 << endl;
        }
    }
}