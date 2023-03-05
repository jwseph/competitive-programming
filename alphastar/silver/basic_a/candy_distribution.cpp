#include <bits/stdc++.h>
using namespace std;

int N, K, A[15], cnt = 0;
tuple<bool, int, int> R[50];

bool yay() {
    for (int i = 0; i < K; ++i) {
        auto& r = R[i];
        bool eq = A[get<1>(r)] == A[get<2>(r)];
        if (eq != get<0>(r)) {
            return false;
        }
    }
    return true;
}

void dfs(int i) {
    if (i == N) {
        if (yay()) ++cnt;
        return;
    }
    for (int T = 0; T < 3; ++T) {
        A[i] = T;
        dfs(i+1);
    }
}

int main() {
    cin >> N >> K;
    for (int i = 0; i < K; ++i) {
        char P; int A, B; cin >> P >> A >> B;
        get<0>(R[i]) = P == 'S';
        get<1>(R[i]) = A-1;
        get<2>(R[i]) = B-1;
    }
    dfs(0);
    cout << cnt << endl;
}