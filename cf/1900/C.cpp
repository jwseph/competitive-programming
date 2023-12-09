#include <bits/stdc++.h>
using namespace std;

#define MAXN 300'000

struct node {
    node *left, *right;
    char dir;
};

int NT, N;
string S;
node* A[MAXN];

int sol(node* n) {
    if (!n) return 1e9;
    if (!n->left && !n->right) return 0;
    int l = (n->dir != 'L') + sol(n->left);
    int r = (n->dir != 'R') + sol(n->right);
    return min(l, r);
}

int main() {
    cin >> NT;
    while (NT--) {
        cin >> N >> S;
        for (int i = 0; i < N; ++i) A[i] = new node;
        for (int i = 0; i < N; ++i) {
            int l, r; cin >> l >> r;
            A[i]->left = l ? A[l-1] : NULL;
            A[i]->right = r ? A[r-1] : NULL;
            A[i]->dir = S[i];
        }
        cout << sol(A[0]) << endl;
        for (int i = 0; i < N; ++i) delete A[i];
    }

}