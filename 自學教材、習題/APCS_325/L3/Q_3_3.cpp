#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define fi first
#define se second
#define INF LONG_LONG_MAX/1000
#define WA() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define all(x) (x).begin(), (x).end()
#define int long long
#define PII pair<int, int>

signed main() { WA();
    string s; cin >> s;
    deque<int> dq;
    for (auto &c : s) {
        if (dq.size() && dq.back() == '*'-9999999) {
            dq.pop_back();
            int result = (c-'0')*dq.back(); dq.pop_back();
            dq.push_back(result);
        }
        else if (dq.size() && dq.back() == '/'-9999999) {
            dq.pop_back();
            int result = dq.back()/(c-'0'); dq.pop_back();
            dq.push_back(result);
        }
        else {
            if (isdigit(c)) dq.push_back(c-'0');
            else dq.push_back(c-9999999);
        }
    }
    int ans = dq.front(); dq.pop_front();
    while (dq.size()) {
        if (dq.front() == '+'-9999999) {
            dq.pop_front();
            ans += dq.front(); dq.pop_front();
        }
        else {
            dq.pop_front();
            ans -= dq.front(); dq.pop_front();
        }
    }
    cout << ans;
}