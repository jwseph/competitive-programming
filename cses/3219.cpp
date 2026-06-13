#include <bits/stdc++.h>
using namespace std;

set<int> s;
map<int, int> cnt;
int n, k, a[200005];

int main() {
    cin >> n >> k;
    for (int i = 0; i < k+1; ++i) {
        s.insert(i);
    }
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        s.erase(a[i]);
        cnt[a[i]]++;
        if (i-k >= 0) {
            if (!--cnt[a[i-k]]) {
                s.insert(a[i-k]);
            }
        }
        if (i >= k-1) {
            cout << *s.begin() << ' ';
        }
    }
}