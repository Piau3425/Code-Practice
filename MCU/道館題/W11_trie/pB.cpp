#include <bits/stdc++.h>
using namespace std;

#define WA() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define int long long

struct Node {
    bool isWord = false;
    int w = 0;
    unordered_map<char, Node*> child;
};

void insert(Node *p, string s) {
    for (auto c : s) {
        if (!p -> child[c]) p -> child[c] = new Node;
        p = p -> child[c];
        p -> w += 1;
    }
    p -> isWord = true;
}

int search(Node *p, string s) {
    for (auto c : s) {
        if (p -> child[c]) p = p -> child[c];
        else return 0;
    }
    return p -> w;
}

signed main() { WA();
    int t;
    for (cin >> t; t; t--) {
        int n, q;
        string s;
        Node *root = new Node;
        cin >> n >> q;
        while (n--) {
            cin >> s;
            insert(root, s);
        }
        while (q--) {
            cin >> s;
            cout << search(root, s) << '\n';
        }
    }
}