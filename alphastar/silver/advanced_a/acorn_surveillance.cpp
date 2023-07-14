#include <bits/stdc++.h>
using namespace std;

#define MAXN 100'000
#define pii pair<int, int>

int N;
pii intervals[MAXN];
vector<pii> on, off;
unordered_map<int, int> only_one;  // Total amount of time only one camera is on

int main() {
    cin >> N;
    for (int i = 0; i < N; ++i) {
        int A, B; cin >> A >> B;
        intervals[i] = {A, B};
        on.push_back({A, i});
        off.push_back({B, i});
    }
    sort(on.begin(), on.end());
    sort(off.begin(), off.end());
    int t = 0, cur_on = 0, total_time_on = 0;
    int i = 0, j = 0;
    int res = INT_MAX;
    while (i < N || j < N) {
        if (i < N && (j == N || on[i].first < off[j].first)) {
            // Take from `on`
            int t2 = on[i].first;
            total_time_on += cur_on > 0 ? t2-t : 0;
            only_one[t2] = only_one[t] + (cur_on == 1 ? t2-t : 0);
            t = t2;

            ++cur_on;
            ++i;
        } else {
            // Take from `off`
            int t2 = off[j].first;
            total_time_on += cur_on > 0 ? t2-t : 0;
            only_one[t2] = only_one[t] + (cur_on == 1 ? t2-t : 0);
            t = t2;

            int on_t = intervals[off[j].second].first;
            res = min(res, only_one[t]-only_one[on_t]);

            --cur_on;
            ++j;
        }
    }
    cout << total_time_on-res << endl;
}