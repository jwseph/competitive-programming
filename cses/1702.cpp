#include <bits/stdc++.h>
using namespace std;

struct Node {
    int val;
    Node *left = nullptr, *right = nullptr;
};

const int N = 1e5+5;
int n;
int pre[N], idx[N];
stack<pair<int, Node*>> s;

void dfs(Node* node) {
    if (!node) return;
    dfs(node->left);
    dfs(node->right);
    cout << node->val << ' ';
}

int main() {
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> pre[i];
    }
    for (int i = 0; i < n; ++i) {
        int a; cin >> a;
        idx[a] = i;
    }
    Node* root;
    for (int i = 0; i < n; ++i) {
        Node *node = new Node{pre[i]};
        if (!i) root = node;
        pair<int, Node*> p = {idx[pre[i]], node};
        if (s.size() && p < s.top()) {
            s.top().second->left = node;
        }
        Node* par = nullptr;
        while (s.size() && p > s.top()) {
            par = s.top().second;
            s.pop();
        }
        if (par) par->right = node;
        s.push(p);
    }
    dfs(root);
    cout << endl;
}