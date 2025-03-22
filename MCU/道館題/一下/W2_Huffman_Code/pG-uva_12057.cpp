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
#define PDS pair<double, set<int>>
#define PIS pair<int, set<int>>
#define PIV pair<int, vector<int>>
#define TIDS tuple<int, double, set<int>>

signed main() { WA();
    int n;
    while (cin >> n) {
        vector<pair<double, string>> v(n); // 索引值 = 機率 : 霍夫曼編碼
        queue<PIV> q; // {合併次數, 節點儲存的編碼}，由小到大
        stack<PIV> s;
        for (auto &i : v) {
            cin >> i.fi;
            q.push({0, vector<int>{&i - &v.front()}});
        }
        //if (q.size() & 1) q.push({999, set<int>{}});

        while (q.size() || s.size() > 1) {
            if (s.size() >= 2) {
                auto [depthA, setA] = s.top(); s.pop();
                auto [depthB, setB] = s.top(); s.pop();

                if (depthA == depthB) {
                    for (auto i : setA) v[i].se = "1" + v[i].se;
                    for (auto i : setB) v[i].se = "0" + v[i].se;
                    setA.insert(setA.begin(), all(setB));
                    s.push({depthA + 1, setA});
                    continue;
                }
                else {
                    s.push({depthB, setB});
                    s.push({depthA, setA});
                }
            }
            
            if (q.size()) s.push(q.front()), q.pop();
            else break;
        }   

        for (auto [prob, huff] : v) cout << fixed << setprecision(4) << prob << ' ' << huff << '\n';
        cout << '\n';
    }
}