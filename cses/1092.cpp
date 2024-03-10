#include <bits/stdc++.h>
using namespace std;

#define ll long long

int N;
vector<int> A, B;

int main() {
    cin >> N;
    ll cur = (ll)N*(N+1)/2;
    if (cur&1) {
        cout << "NO" << endl;
        return 0;
    }
    cout << "YES" << endl;
    cur /= 2;
    for (int i = N; i >= 1; --i) {
        if (cur-i >= 0) {
            cur -= i;
            A.push_back(i);
            continue;
        }
        B.push_back(i);
    }
    cout << A.size() << endl;
    for (int a: A) cout << a << ' ';
    cout << endl;
    cout << B.size() << endl;
    for (int b: B) cout << b << ' ';
    cout << endl;
}