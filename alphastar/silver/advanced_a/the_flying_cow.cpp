#include <bits/stdc++.h>
using namespace std;

#define MAXN 1'000'000

int N;
bool V[MAXN+100]{};
queue<int> Q;

int main() {
    cin >> N;
    V[1] = 1;
    Q.push(1);
    for (int res = 0; Q.size(); ++res)
    for (int s = Q.size(); s > 0; --s) {
        int i = Q.front(); Q.pop();
        if (i == N) {
            cout << res << endl;
            return 0;
        }
        int A[] = {i-1, i+1, 3*i};
        for (int j: A) {
            if (j < 1 || j >= N+100 || V[j]) continue;
            V[j] = 1;
            Q.push(j);
        }
    }
}