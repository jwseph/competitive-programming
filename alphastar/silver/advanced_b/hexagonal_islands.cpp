#include <bits/stdc++.h>
using namespace std;

#define MAXK 50
#define MAXN 7500

int K, P[3*MAXK];
vector<int> A[MAXN];
bool V[MAXN];
queue<int> Q;

void link(int i, int j) {
    A[i].push_back(j);
    A[j].push_back(i);
}

int main() {
    cin >> K;
    P[0] = 0;
    for (int c = 0; c < K; ++c) P[c+1] = P[c] + K+c;
    for (int c = K; c < 2*K-1; ++c) P[c+1] = P[c] + 3*K-2-c;
    for (int c = 0; c < 2*K-1; ++c) {
        for (int r = 1; r < P[c+1]-P[c]; ++r) {
            link(P[c]+r, P[c]+r-1);
        }
    }
    for (int c = 0; c < K-1; ++c) {
        for (int r = 0; r < P[c+1]-P[c]; ++r) {
            link(P[c]+r, P[c+1]+r);
            link(P[c]+r, P[c+1]+r+1);
        }
    }
    for (int c = K; c < 2*K-1; ++c) {
        for (int r = 0; r < P[c+1]-P[c]; ++r) {
            link(P[c]+r, P[c-1]+r);
            link(P[c]+r, P[c-1]+r+1);
        }
    }
    int H, L; cin >> H >> L; --H;
    Q.push(H);
    V[H] = 1;
    while (L--) {
        for (int qs = Q.size(); qs > 0; --qs) {
            int i = Q.front();
            Q.pop();
            for (int j: A[i]) {
                if (V[j]) continue;
                V[j] = 1;
                Q.push(j);
            }
        }
    }
    vector<int> R;
    while (Q.size()) {
        R.push_back(Q.front());
        Q.pop();
    }
    sort(begin(R), end(R));
    cout << R.size() << endl;
    for (int x: R) cout << x+1 << endl;
}