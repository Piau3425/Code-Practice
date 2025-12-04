#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define fi first
#define se second
#define INF LONG_LONG_MAX/1000
#define WA() cin.tie(0)->sync_with_stdio(0)
#define all(x) (x).begin(), (x).end()
#define int long long
#define PII pair<int, int>

signed main() { WA();
    int n;
    while (cin >> n) {
        string s;
        deque<char> dq(n);
        for (auto &i : dq) cin >> i;
        while (n--) {
            if (dq.front() == '0') s += dq.front(), dq.pop_front();
            else if (dq.back() == '0') s += dq.back(), dq.pop_back();
            else {
                deque<char> xixi = dq; xixi.pop_back(); if (xixi.size()) xixi.pop_front();
                if (xixi.size() && find(all(xixi), '1')-xixi.begin() >= xixi.size()/2) s += dq.front(), dq.pop_front();
                else s += dq.back(), dq.pop_back();
            }
        }
        cout << s << '\n';
    }
}