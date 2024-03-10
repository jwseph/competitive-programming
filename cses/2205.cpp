#include <bits/stdc++.h>
using namespace std;

int N;
vector<string> A = {""};

int main() {
    cin >> N;
    while (N--) {
        for (int i = A.size()-1; i >= 0; --i) {
            A.push_back(A[i]);
        }
        for (int i = 0; i < A.size(); ++i) {
            A[i] += '0'+(i*2/A.size());
        }
    }
    for (string S: A) cout << S << endl;
}