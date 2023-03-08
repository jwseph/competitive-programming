#include <bits/stdc++.h>
using namespace std;

#define N_MAX 1000

int N;
bool V[N_MAX]{};
int A[N_MAX];
queue<int> T[N_MAX];

bool cmp(int a, int b) {
    return A[a] > A[b];
}

int main() {
    cin >> N;
    for (int i = 0; i < N; ++i) {
        cin >> A[i];
        int M; cin >> M;
        while (M--) {
            int j; cin >> j; --j;
            T[i].push(j);
        }
    }
    int t = 0;
    priority_queue<int, vector<int>, decltype(&cmp)> Q(&cmp);
    Q.push(0);
    V[0] = true;
    while (!Q.empty()) {
        int i = Q.top();
        Q.pop();
        t = A[i];
        while (!T[i].empty()) {
            int j = T[i].front();
            T[i].pop();
            if (V[j]) continue;
            V[j] = true;
            A[j] += t;
            Q.push(j);
        }
    }
    cout << t << endl;
}