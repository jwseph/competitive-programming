#include <bits/stdc++.h>
using namespace std;

#define MAX 40'001

bool cmpy(int &a, int &b) {
    return a%MAX < b%MAX;
}

int N;
int A[50'000];
deque<int> B;
int res;

int area() {
    sort(B.begin(), B.end());
    int w = B.back()/MAX-B.front()/MAX;
    sort(B.begin(), B.end(), cmpy);
    int h = B.back()%MAX-B.front()%MAX;
    return w*h;
}

int rem(int dir) {
    if (dir < 2) sort(B.begin(), B.end());
    else sort(B.begin(), B.end(), cmpy);
    if (dir%2) {
        int res = B.front();
        B.pop_front();
        return res;
    } else {
        int res = B.back();
        B.pop_back();
        return res;
    }
}
void add(int dir, int val) {
    if (dir < 2) sort(B.begin(), B.end());
    else sort(B.begin(), B.end(), cmpy);
    if (dir%2) B.push_front(val);
    else B.push_back(val);
}

int main() {
    cin >> N;
    for (int i = 0; i < N; ++i) {
        int x, y; cin >> x >> y;
        A[i] = x*MAX+y;
    }
    sort(A, A+N);
    for (int i = 0; i < 4; ++i) B.push_back(A[i]);
    for (int i = 0; i < 4; ++i) B.push_back(A[N-1-i]);
    sort(A, A+N, cmpy);
    for (int i = 0; i < 4; ++i) B.push_back(A[i]);
    for (int i = 0; i < 4; ++i) B.push_back(A[N-1-i]);

    sort(B.begin(), B.end());
    B.erase(unique(B.begin(), B.end()), B.end());  // remove dupe trees

    res = INT_MAX;
    for (int i = 0; i < 4; ++i) {
        int a = rem(i);
        for (int j = 0; j < 4; ++j) {
            int b = rem(j);
            for (int k = 0; k < 4; ++k) {
                int c = rem(k);
                res = min(res, area());
                add(k, c);
            }
            add(j, b);
        }
        add(i, a);
    }
    cout << res << endl;
}