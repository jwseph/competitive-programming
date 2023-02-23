#include <bits/stdc++.h>
using namespace std;

int N;
deque<int> D;

int main() {
    cin >> N;
    int cnt = 0;
    while (N--) {
        char Q, S; cin >> Q >> S;
        if (Q == 'A') {
            if (S == 'L') D.push_front(++cnt);
            else D.push_back(++cnt);
        }
        if (Q == 'D') {
            int K; cin >> K;
            while (K--) {
                if (S == 'L') D.pop_front();
                else D.pop_back();
            }
        }
    }
    while (!D.empty()) {
        cout << D.front() << endl;
        D.pop_front();
    }
}