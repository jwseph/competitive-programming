#include <bits/stdc++.h>
using namespace std;

int A, B, C;
unordered_set<int> V;
vector<int> res;

void dfs(int a, int b, int c) {
    if (V.find(a*B*C+b*C+c) != V.end()) return;
    V.insert(a*B*C+b*C+c);
    if (a == 0) res.push_back(c);
    // a->b, a->c, b->a, b->c, c->a, c->b
    dfs(max(0, a+b-B), min(a+b, B), c);
    dfs(max(0, a+c-C), b, min(a+c, C));
    dfs(min(a+b, A), max(0, a+b-A), c);
    dfs(a, max(0, b+c-C), min(b+c, C));
    dfs(min(a+c, A), b, max(0, a+c-A));
    dfs(a, min(b+c, B), max(0, b+c-B));
}

int main() {
    cin >> A >> B >> C;
    dfs(0, 0, C);
    sort(begin(res), end(res));
    for (int i: res) cout << i << ' ';
    cout << endl;
}