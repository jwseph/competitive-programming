#include <bits/stdc++.h>
using namespace std;

using arr9 = array<int, 9>;

vector<pair<int, int>> edges = {
    {0, 1}, {1, 2},
    {3, 4}, {4, 5},
    {6, 7}, {7, 8},
    {0, 3}, {3, 6},
    {1, 4}, {4, 7},
    {2, 5}, {5, 8}
};

int tens[] = {1, 10, 100, 1000, 10000, 100000, 1000000, 10000000, 100000000};

queue<int> q;
unordered_set<int> v;

int main() {
    int s = 0;
    for (int i = 0; i < 9; ++i) {
        int x; cin >> x;
        s = s*10+x;
    }
    v.reserve(362880);
    v.insert(s);
    q.push(s);
    for (int d = 0; q.size(); ++d) {
        for (int qs = q.size(); qs --> 0;) {
            int a = q.front(); q.pop();
            if (a == 123456789) {
                cout << d << endl;
                return 0;
            }
            for (const auto& [i, j]: edges) {
                int ti = tens[i], tj = tens[j];
                int x = a/ti % 10, y = a/tj % 10;
                int b = a - x*ti - y*tj + x*tj + y*ti;
                if (!v.insert(b).second) continue;
                q.push(b);
            }
        }
    }
}