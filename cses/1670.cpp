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

void get_adj(arr9 a, vector<arr9>& adj) {
    for (auto [i, j]: edges) {
        auto b = a;
        swap(b[i], b[j]);
        adj.push_back(b);
    }
}

queue<arr9> q;
set<arr9> v;

int main() {
    arr9 s;
    for (int i = 0; i < 9; ++i) {
        cin >> s[i];
    }
    q.push(s);
    for (int d = 0; q.size(); ++d) {
        for (int qs = q.size(); qs --> 0;) {
            arr9 a = q.front(); q.pop();
            if (a == arr9{1, 2, 3, 4, 5, 6, 7, 8, 9}) {
                cout << d << endl;
                return 0;
            }
            vector<arr9> adj;
            get_adj(a, adj);
            for (arr9 b: adj) {
                if (v.count(b)) continue;
                v.insert(b);
                q.push(b);
            }
        }
    }
}