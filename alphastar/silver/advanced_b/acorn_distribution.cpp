#include <bits/stdc++.h>
using namespace std;

#define MAXN 100000

int K, N, P;
queue<int> Q;
vector<int> R;

int main() {
    cin >> K >> N >> P;
    for (int i = 1; i <= N; ++i) Q.push(i);
    int k = 1;
    while (Q.size()) {
        int i = Q.front();
        Q.pop();
        if (k == 0) R.push_back(i);
        k = (k+1)%K;
        for (int p = 0; p < P && Q.size(); ++p) {
            Q.push(Q.front());
            Q.pop();
        }
    }
    sort(begin(R), end(R));
    for (int r: R) cout << r << endl;
}