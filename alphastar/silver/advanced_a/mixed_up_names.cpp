#include <bits/stdc++.h>
using namespace std;

#define MAXN 50'000

int N;
string A[MAXN], m[MAXN], M[MAXN];

int main() {
    cin >> N;
    for (int i = 0; i < N; ++i) {
        cin >> A[i];
        m[i] = M[i] = A[i];
        sort(m[i].begin(), m[i].end());
        sort(M[i].rbegin(), M[i].rend());
    }
    sort(m, m+N);
    sort(M, M+N);
    for (int i = 0; i < N; ++i) {
        string S = A[i];
        sort(S.begin(), S.end());
        int l = lower_bound(M, M+N, S)-M;
        sort(S.rbegin(), S.rend());
        int r = upper_bound(m, m+N, S)-m-1;
        cout << l+1 << ' ' << r+1 << endl;
    }
}