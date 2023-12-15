#include <bits/stdc++.h>
using namespace std;

int N;
vector<tuple<int, int, int, int, int>> A;

int main() {
    cin >> N;
    int res = 0;
    for (int i = 0; i < N; ++i) {
        int l1, d1, r1, u1; cin >> l1 >> d1 >> r1 >> u1;
        int t1 = 1;
        for (int j = A.size()-1; j >= 0; --j) {
            auto [l2, d2, r2, u2, t2] = A[j];
            if (r2 <= l1 || r1 <= l2 || d2 <= u1 || d1 <= u2) continue;
            int l3 = max(l1, l2), r3 = min(r1, r2);
            int u3 = max(u1, u2), d3 = min(d1, d2);
            int t3 = -t1*t2;
            A.push_back({l3, d3, r3, u3, t3});
            res += (r3-l3)*(d3-u3)*t3;
        }
        A.push_back({l1, d1, r1, u1, t1});
        res += (r1-l1)*(d1-u1)*t1;
    }
    cout << res << endl;
}