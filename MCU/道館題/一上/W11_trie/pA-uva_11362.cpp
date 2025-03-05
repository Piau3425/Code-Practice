#include <bits/stdc++.h>
using namespace std;

#define WA() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)

bool checker;

struct Node {
    bool isWord;
    Node *child[10];
    Node() {
        for (auto &c : child) c = NULL;
        isWord = false;
    }
};

void insert(Node *p, string s) {
    for (auto &c : s) {
        int i = c - '0';
        if ((p -> child[i] && p -> child[i] -> isWord) || (&c == &s.back() && p -> child[i])) {
            checker = true;
            return;
        }
        else if (!p -> child[i]) p -> child[i] = new Node;
        p = p -> child[i];
    }
    p -> isWord = true;
}

int main() { WA();
    int t;
    for (cin >> t; t; t--) {
        int n;
        Node *root = new Node;
        cin >> n;
        vector<string> v(n);
        checker = false;

        for (auto &i : v) cin >> i;
        for (auto i : v) {
            insert(root, i);
            if (checker) break;
        }
        
        if (checker) cout << "NO\n";
        else cout << "YES\n";
    }
}