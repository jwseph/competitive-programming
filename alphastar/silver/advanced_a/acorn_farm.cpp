#include <bits/stdc++.h>
using namespace std;

#define MAXN 100'000

int N, A;

unordered_map<int, int> O;
map<int, int, greater<int>> cnt;  // {score, number of trees with that score}
vector<vector<int>> V;

int main() {
    cin >> N >> A;
    for (int i = 0; i < N; ++i) {
        int D, T, C; cin >> D >> T >> C;
        V.push_back({D, T, C});
    }
    sort(V.begin(), V.end());
    cnt[0] = N+1;
    int res = 0;
    for (int i = 0; i < N; ++i) {
        int D = V[i][0], T = V[i][1], C = V[i][2];
        int oldScore = O[T], oldTopScore = cnt.begin()->first;
        O[T] += C;
        int newScore = O[T];
        if (!--cnt[oldScore]) cnt.erase(oldScore);
        ++cnt[newScore];
        int newTopScore = cnt.begin()->first;
        if (oldScore == oldTopScore && newScore == newTopScore && !cnt.count(oldScore) && cnt[newScore] == 1) {
            continue;
        }
        res += oldScore == oldTopScore || newScore == newTopScore;
    }
    cout << res << endl;
}