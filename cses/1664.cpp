#include <bits/stdc++.h>
using namespace std;

// Continually pick the range that ends first.
// After using a range, pick the range ending first whose start time is after the range's end time.
//
// Store as array[start] = min end time    OR array[start] = end time of range (min if duplicate)
// Find min end time after the range ends. Use that range
//
// Find min ending time of 2^k movies after start time t
// = min ending time of 2^(k-1) movies after start time t
//   + find start time t of next min ending movie -> min ending time of 2^(k-1) movies after that start time
// NEED: start time of min ending movie after start time t
// find min (end, start) after all start times

const int N = 1e6+6, L = 21;
int n, m;
int et[N][L];

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin >> n >> m;
    for (int i = 0; i < N; ++i) {
        et[i][0] = N-1;
    }
    for (int i = 0; i < n; ++i) {
        int l, r; cin >> l >> r;
        et[l][0] = min(et[l][0], r);
    }
    for (int i = N-2; i >= 0; --i) {
        et[i][0] = min(et[i][0], et[i+1][0]);
    }
    for (int j = 1; j < L; ++j) {
        for (int i = 0; i < N; ++i) {
            et[i][j] = et[et[i][j-1]][j-1];
        }
    }
    while (m--) {
        int l, r; cin >> l >> r;
        int i = l, res = 0;
        for (int j = L-1; j >= 0; --j) {
            if (et[i][j] <= r) {
                i = et[i][j];
                res += 1<<j;
            }
        }
        cout << res << endl;
    }
}