/*

each t associated with at most one s.
if we fix t for [1, nw], we can determine s in O(n) by simulating the game, passing through the list once while maintaining some counter variables. if s doesn't exist for that t, we'd be able to determine that also. Because nw is bounded by n, the overall complexity would be O(n^2).

We can optimize this. Notice the max sets is ~n for t=1, ~n/2 for t=2, ~n/3 for t=3, etc. So the max total sets is n+n/2+n/3+...+n/n = nlogn. Between each set there's a divider index. If we can jump between splits instantly, then we get O(nlogn) overall.

Actually, we can jump between the splits. Let's create prefix arrays for both players' wins. From the start of each set, binary search for the indexes when both players would win t more serves. The player that reaches t serves first wins the set. That index becomes the start index for the next set. There are some edge cases to consider: handling when neither player reaches t serves; ensuring player who wins the final serve wins the final set, ensuring winning player won more sets.

Because binary search is O(logn) the overall time is O(n log^2 n).

*/

#include <bits/stdc++.h>
using namespace std;

const int N = 1e5+5;
int n, a[N], p[N], q[N];
vector<array<int, 2>> res;

int sol(int t) {
    int i = 0, s_won = 0, s_lost = 0;
    while (i < n) {
        int w = lower_bound(p, p+n+1, p[i]+t) - p;
        int l = lower_bound(q, q+n+1, q[i]+t) - q;
        if (w < l) {
            i = w;
            s_won++;
            continue;
        }
        if (l < w) {
            i = l;
            s_lost++;
            continue;
        }
        bool wok = p[w]-p[i] == t;
        bool lok = q[l]-q[i] == t;
        if (!wok) return -1;
        i = w;
        s_won++;
    }
    if (s_won <= s_lost) return -1;
    return s_won;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        a[i]--;
    }
    for (int i = 0; i < n; ++i) {
        a[i] ^= a[n-1]^1;
        p[i+1] = p[i] + a[i];
        q[i+1] = q[i] + 1-a[i];
    }
    for (int t = 1; t <= p[n]; t++) {
        int s = sol(t);
        if (s < 0) continue;
        res.push_back({s, t});
    }
    sort(res.begin(), res.end());
    cout << res.size() << endl;
    for (auto [s, t]: res) {
        cout << s << ' ' << t << endl;
    }
}