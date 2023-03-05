#include <bits/stdc++.h>
using namespace std;

int N;
deque<pair<int, int>> P;  // milk output, count

int main() {
    cin >> N;
    for (int i = 0; i < N; ++i) {
        int A, B; cin >> B >> A;
        P.push_back({A, B});
    }
    sort(P.begin(), P.end());
    int res = -1;
    while (P.size() > 1) {
        int cnt = min(P.front().second, P.back().second);
        res = max(res, P.front().first+P.back().first);
        P.front().second -= cnt;
        P.back().second -= cnt;
        if (P.front().second == 0) P.pop_front();
        if (P.back().second == 0) P.pop_back();
    }
    if (!P.empty() && P.front().second > 1) {
        res = max(res, 2*P.front().first);
    }
    cout << res << endl;
}