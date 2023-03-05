#include <bits/stdc++.h>
using namespace std;

int cap;
bool cmp(int& a, int& b) {
    return a%cap > b%cap;
}

int main() {
    int n, k; cin >> n >> k;
    int b[n], bM = 0;
    for (int i = 0; i < n; ++i) {
        cin >> b[i];
        bM = max(bM, b[i]);
    }
    int res = 0;
    for (cap = 1; cap <= bM; ++cap) {
        int nb = 0;
        for (int& tree: b) {
            nb += tree/cap;
        }
        if (nb < k/2) continue;
        if (nb >= k) {
            res = max(res, k/2*cap);
            continue;
        }
        sort(b, b+n, cmp);
        int berries = cap*(nb-k/2);
        for (int i = 0; i+nb < k && i < n; ++i) {
            berries += b[i]%cap;
        }
        res = max(res, berries);
    }
    cout << res << endl;
}