#include <bits/stdc++.h>
using namespace std;

int main() { ios::sync_with_stdio(0); cin.tie(0);
    int n, mx = -1e9;
    vector<int> v(10005, 0);
    priority_queue<int> l;
    priority_queue<int, vector<int>, greater<int>> r;
    
    while (cin >> n && n) {
        if (l.empty() || n <= l.top()) l.push(n);
        else r.push(n);

        if (l.size()-1 > r.size()) {
            r.push(l.top());
            l.pop();
        }
        else if (r.size() > l.size()) {
            l.push(r.top());
            r.pop();
        }

        if (l.size() > r.size()) cout << l.top() << '\n';
        else cout << (l.top() + r.top())/2 << '\n';
    }
}