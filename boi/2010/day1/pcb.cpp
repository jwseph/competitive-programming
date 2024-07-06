#include <bits/stdc++.h>
using namespace std;

using pii = array<int, 2>;
#define FOR(i,a,b) for (int i = (a); i < (b); ++i)

const int N = 1e5+5;
int n;
pii ar[N];
multiset<int> levels;

int main() {
    cin >> n;
    FOR(i, 0, n) {
        int l, r; cin >> l >> r;
        ar[i] = {l, r};
    }
    sort(ar, ar+n);
    int res = 0;
    FOR(i, 0, n) {
        auto [l, r] = ar[i];
        auto it = levels.lower_bound(r);
        if (it == levels.begin()) res++;
        else levels.erase(--it);
        levels.insert(r);
    }
    cout << res << endl;
}