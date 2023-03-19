#include <bits/stdc++.h>
using namespace std;

#define N_MAX 100'000

int N;
pair<int, int> A[N_MAX];

bool cmp(pair<int, int>& a, pair<int, int>& b) {
    if (a.first != b.first) return a.first < b.first;
    return a.second > b.second;
}

int main() {
    cin >> N;
    for (int i = 0; i < N; ++i) {
        int X, Y; cin >> X >> Y;
        A[i] = {X-Y, X+Y};
    }
    sort(A, A+N, cmp);
    int res = N, Mr = INT_MIN;
    for (int i = 0; i < N; ++i) {
        if (A[i].second <= Mr) {
            --res;
        }
        Mr = max(Mr, A[i].second);
    }
    cout << res << endl;
}