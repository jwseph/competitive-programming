#include <bits/stdc++.h>
using namespace std;

#define N_MAX 100'000

int C, N;
pair<int, int> A[N_MAX];
multiset<int> T;

int main() {
    cin >> C >> N;
    for (int i = 0; i < C; ++i) {
        int t; cin >> t; T.insert(t);
    }
    for (int i = 0; i < N; ++i) {
        cin >> A[i].second >> A[i].first;
    }
    sort(A, A+N);
    int cnt = 0;
    for (int j = 0; j < N; ++j) {
        auto it = T.lower_bound(A[j].second);
        if (it == T.end() || A[j].first < *it) continue;
        T.erase(it);
        ++cnt;
    }
    cout << cnt << endl;
}