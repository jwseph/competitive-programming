#include <bits/stdc++.h>
using namespace std;

#define sz(x) int((x).size())

int N;
vector<int> A;

int main() {
    // Basically LIS and count
    cin >> N;
    while (N--) {
        int a; cin >> a;
        int i = upper_bound(begin(A), end(A), a) - begin(A);
        if (i == sz(A)) A.push_back(-1);
        A[i] = a;
    }
    cout << sz(A) << endl;
}