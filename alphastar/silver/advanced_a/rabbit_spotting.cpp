#include <bits/stdc++.h>
using namespace std;

int N, A, B;
set<int> S, NS;

int main() {
    cin >> N >> A >> B; ++B;
    for (int i = 0; i < N; ++i) {
        string s; int W; cin >> s >> W;
        (s == "S" ? S : NS).insert(W);
    }
    S.insert(INT_MAX);
    NS.insert(INT_MAX);
    int t = A, res = 0;
    auto s = S.begin(), ns = NS.begin();
    while (t < B) {
        if (*s < *ns) {
            int T = min(B, max(t, *s+(*ns-*s)/2+1));
            res += T-t;
            t = T;
            ++s;
        } else {
            t = min(B, max(t, *ns+(*s-*ns+1)/2));
            ++ns;
        }
    }
    cout << res << endl;
}