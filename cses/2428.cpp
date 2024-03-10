#include <bits/stdc++.h>
using namespace std;

const int MAXN = 2e5+5;

int N, K, A[MAXN];
map<int, int> cnt;

int main() {
    cin >> N >> K;
    for (int i = 0; i < N; ++i) cin >> A[i];
    long long res = 0;
    for (int i = 0, j = 0; j < N; ++j) {
        ++cnt[A[j]];
        while (i < j && cnt.size() > K) {
            if (!--cnt[A[i]]) cnt.erase(A[i]);
            ++i;
        }
        res += j-i+1;
    }
    cout << res << endl;
}