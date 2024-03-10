#include <bits/stdc++.h>
using namespace std;

const int MAXN = 2e5+5;
int N;
int P[MAXN], V[MAXN];
vector<int> A[MAXN];

void dfs(int i, int w) {
    if (V[i] > 0 && V[i] < w) return;
    V[i] = w;
    for (int j: A[i]) {
        dfs(j, w+1);
    }
}

void sol(int i) {
    if (V[i]) return;
    while (!V[i]) {
        V[i] = -1;
        i = P[i];
    }
    vector<int> cycle;
    while (V[i] == -1) {
        V[i] = -2;
        cycle.push_back(i);
        i = P[i];
    }
    while (V[i] == -2) {
        V[i] = cycle.size();
        i = P[i];
    }
    for (int a: cycle) {
        dfs(a, cycle.size());
    }
}

int main() {
    cin >> N;
    for (int i = 1; i <= N; ++i) {
        cin >> P[i];
        A[P[i]].push_back(i);
    }
    for (int i = 1; i <= N; ++i) {
        sol(i);
        cout << V[i] << ' ';
    }
    cout << endl;
}