#include <bits/stdc++.h>
using namespace std;

const int N = 2e5+5;

int p[N], deg[N];
priority_queue<int, vector<int>, greater<int>> pq;

int main() {
    int n; cin >> n;
    for (int e = 0; e < n-2; ++e) {
        cin >> p[e];
        deg[p[e]]++;
    }
    for (int i = 1; i <= n; ++i) {
        if (deg[i] == 0) {
            pq.push(i);
        }
    }
    for (int e = 0; e < n-2; ++e) {
        int j = p[e];
        int i = pq.top(); pq.pop();
        cout << i << ' ' << j << endl;
        deg[i]--;
        deg[j]--;
        if (deg[j] == 0) {
            pq.push(j);
        }
    }
    for (int i = 1; i <= n; ++i) {
        if (deg[i] == 0) cout << i << ' ';
    }
    cout << endl;
}