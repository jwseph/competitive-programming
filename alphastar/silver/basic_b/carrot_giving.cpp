#include <bits/stdc++.h>
using namespace std;

#define MAXN 1000

int N;
double B;
pair<double, double> A[MAXN];

int main() {
    cin >> N >> B;
    for (int i = 0; i < N; ++i) {
        int p, s; cin >> p >> s;
        A[i] = {p+s, p/2+s};
    }
    sort(A, A+N);
    int i = 0;
    double cost = 0, maxSave = -1;
    while (i < N && cost+A[i].first <= B) {
        cost += A[i].first;
        maxSave = max(maxSave, A[i].first-A[i].second);
        ++i;
    }
    int res = i;
    for (int j = i; j < N; ++j) {
        if (A[j].second+cost <= B) {
            res = max(res, i+1);
            break;
        }
    }
    cost -= maxSave;
    int j = i;
    while (j < N && cost+A[j].first <= B) {
        cost += A[j].first;
        ++j;
    }
    res = max(res, j);
    cout << res << endl;
}