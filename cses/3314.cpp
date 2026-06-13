#include <bits/stdc++.h>
using namespace std;

template<class T>
struct Tree {
    static constexpr T def{};
    T f(T a, T b) { return max(a, b); }
    vector<T> t; int n;
    Tree(int n): t(2*n, def), n(n) {}
    void update(int i, T v) {
        for (t[i += n] = v; i /= 2;) t[i] = f(t[i*2], t[i*2+1]);
    }
    T query(int l, int r) {
        T al = def, ar = def;
        for (l += n, r += n; l < r; l /= 2, r /= 2) {
            if (l&1) al = f(al, t[l++]);
            if (r&1) ar = f(t[--r], ar);
        }
        return f(al, ar);
    }
};

const int N = 2e5+5;

int n, a[N], lv[N], rv[N];
Tree<int> dp(N);

bool cmp(int i, int j) {
    return a[i] < a[j];
}

int main() {
    cin >> n;
    vector<int> idx;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
        idx.push_back(i);
    }
    sort(begin(idx), end(idx), cmp);

    // populate left and right vision
    a[0] = a[n+1] = 2e9;
    stack<int> s;
    s.push(0);
    for (int i = 1; i <= n; ++i) {
        while (a[i] > a[s.top()]) s.pop();
        lv[i] = s.top();
        s.push(i);
    }
    s = stack<int>();
    s.push(n+1);
    for (int i = n; i >= 1; --i) {
        while (a[i] > a[s.top()]) s.pop();
        rv[i] = s.top();
        s.push(i);
    }
    
    for (int i: idx) {
        int cur = 1 + max(dp.query(lv[i]+1, i), dp.query(i+1, rv[i]));
        dp.update(i, cur);
    }
    cout << dp.query(1, n+1) << endl;
}