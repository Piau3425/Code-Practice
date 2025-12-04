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

map<set<int>, int> mp;
vector<set<int>> v;

int ID(set<int> x) {
    if (mp.count(x)) return mp[x];
    v.pb(x);
    return mp[x] = v.size()-1;
}

signed main() { WA();
    int n, t;
    cin >> t;
    while (t--) {
        cin >> n;
        stack<int> sta;
        while (n--) {
            string cmd; cin >> cmd;
            if (cmd == "PUSH") sta.push(ID(set<int>()));
            else if (cmd == "DUP") sta.push(sta.top());
            else {
                set<int> a = v[sta.top()]; sta.pop();
                set<int> b = v[sta.top()]; sta.pop();
                set<int> s;
                if (cmd == "ADD") s = b, s.insert(ID(a));
                if (cmd == "UNION") {
                    for (auto i : a) s.insert(i);
                    for (auto i : b) s.insert(i);
                    //set_union(all(a), all(b), inserter(s, s.begin()));
                }
                if (cmd == "INTERSECT") for (auto i : a) if (b.count(i)) s.insert(i); // if (cmd == "INTERSECT") set_intersection(all(a), all(b), inserter(s, s.begin()));
                sta.push(ID(s));
            }
            cout << v[sta.top()].size() << '\n';
        }
        cout << "***\n";
    }
}