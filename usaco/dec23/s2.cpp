#include <bits/stdc++.h>
using namespace std;

#define MAXN 500005

int N, K, A[MAXN], IDX[MAXN], cnt[MAXN];

int lcs() {
    // Longest consecutive substring with blanks
    unordered_map<int, int> cnt2;
    int res = 0;
    for (int i = 0; i < K; ++i) {
        if (A[i] < 0) continue;
        res = max(res, ++cnt2[(A[i]-i+K)%K]);
    }
    return res;
}

int main() {
    memset(IDX, -1, sizeof IDX);
    cin >> N >> K;
    for (int i = 0; i < K; ++i) {
        cin >> A[i];
        ++cnt[A[i]];
    }
    for (int i = 0; i < K; ++i) {
        int b; cin >> b;
        IDX[b] = i;
        ++cnt[b];
    }
    for (int i = 0; i < K; ++i) A[i] = IDX[A[i]];
    int res = lcs();
    for (int i = 0; i < K; ++i) if (A[i] >= 0) A[i] = N-1-A[i];
    res = max(res, lcs());
    for (int i = 1; i <= N; ++i) {
        res += cnt[i] == 0;
    }
    cout << res << endl;
}