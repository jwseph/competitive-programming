#include <bits/stdc++.h>
using namespace std;

const int N = 3003;
using pci = pair<char, int>;

int n;
string a[N];
pci dp[N][N];

int main() {
    cin.tie(0)->sync_with_stdio(false);
    cin >> n;
    for (int r = 0; r < n; ++r) {
        cin >> a[r];
    }
    for (int i = 0; i <= n; ++i) {
        dp[i][n] = {'Z'+1, 0};
        dp[n][i] = {'Z'+1, 0};
    }
    dp[n-1][n-1] = {a[n-1][n-1], 0};

    for (int sum = n*2-3; sum >= 0; --sum) {
        int r_start = min(n-1, sum);
        int r_end = max(0, sum-(n-1));
        vector<pci> diag;
        for (int r = r_start; r >= r_end; --r) {
            int c = sum-r;
            dp[r][c].first = a[r][c];
            dp[r][c].second = min(dp[r+1][c], dp[r][c+1]).second;
            diag.push_back(dp[r][c]);
        }

        // coord compress
        sort(diag.begin(), diag.end());
        diag.erase(unique(diag.begin(), diag.end()), diag.end());

        // cout << "start diag" << endl;
        for (int r = r_start; r >= r_end; --r) {
            int c = sum-r;
            int idx = lower_bound(diag.begin(), diag.end(), dp[r][c]) - diag.begin();
            dp[r][c].second = idx;
            // cout << dp[r][c].first << ',' << dp[r][c].second << ' ';
        }
        // cout << endl;
        // cout << "end diag" << endl << endl;
    }
    
    cout << a[0][0];
    int r = 0, c = 0;
    while (r != n-1 || c != n-1) {
        // cout << "cur = " << dp[r][c].first << ',' << dp[r][c].second << endl;
        // cout << "opts = " << dp[r+1][c].first << ',' << dp[r+1][c].second << " and " << dp[r][c+1].first << ',' << dp[r][c+1].second << endl;
        if (dp[r+1][c] < dp[r][c+1]) r++;
        else c++;
        cout << dp[r][c].first;
    }
    cout << endl;
}