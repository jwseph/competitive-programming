#include <bits/stdc++.h>
using namespace std;

int M, N;
string A[10'000];

int main() {
    cin >> M >> N;
    getline(cin, A[0]);
    for (int i = 0; i < M; ++i) {
        getline(cin, A[i]);
    }
    sort(A, A+N);
    int res = 0;
    for (int i = 0; i < N; ++i) {
        string S; getline(cin, S);
        auto j = lower_bound(A, A+N, S);
        if (j < A+N && !j->compare(0, S.size(), S)) {
            ++res;
        }
    }
    cout << res << endl;
}