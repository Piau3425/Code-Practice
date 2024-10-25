#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main() {
    int n;
    priority_queue<int> l;
    priority_queue<int, vector<int>, greater<int>> r;

    while (cin >> n) {
        if (l.empty() || n <= l.top()) l.push(n);
        else r.push(n);

        if (l.size() -1 > r.size()) {
            r.push(l.top());
            l.pop();
        }
        else if (r.size() > l.size()) {
            l.push(r.top());
            r.pop();
        }

        if (l.size() == r.size()) cout << (l.top() + r.top())/2 << '\n';
        else cout << l.top() << '\n';
    }
}