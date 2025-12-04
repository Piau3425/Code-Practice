// 感謝簡邑豪的簡報 QAQ

#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define INF LONG_LONG_MAX/1000
#define WA() cin.tie(0)->sync_with_stdio(0)
#define all(x) (x).begin(), (x).end()
#define int long long
#define PII pair<int, int>
#define TIII tuple<int, int, int>

signed main() { WA();
    int n, m; cin >> n >> m;
    vector<int> cost(n);
    vector<vector<PII>> g(n);
    for (auto &i : cost) cin >> i;
    while (m--) {
        int a, b, w;
        cin >> a >> b >> w;
        g[a].pb({b, w});
        g[b].pb({a, w}); // 之前寫成單向了 :(
    }

    cin >> m;
    while (m--) {
        int cap, st, ed; cin >> cap >> st >> ed;
        vector<vector<int>> dp(n, vector<int>(cap+1, INF)); // [節點][汽油量] = 花費
        priority_queue<TIII, vector<TIII>, greater<TIII>> pq; // {目前總花費, 目前節點, 剩餘汽油量}
        dp[st][0] = 0;
        pq.push({0, st, 0}); // 目前花費、目前節點、目前汽油量
        while (pq.size()) {
            auto [now_cost, now_node, now_fuel] = pq.top(); pq.pop();
            //if (now_cost > dp[now_node][now_fuel]) continue; 我腦袋當機了，我加這行有用嗎？
            if (now_node == ed) break;
            
            if (now_fuel + 1 <= cap && now_cost + cost[now_node] < dp[now_node][now_fuel+1]) { // 如果目前加油不會超出上限 && 在總花費加上在目前節點加油的價錢比以前紀錄的總花費 (在其他節點加油) 還便宜，就覆蓋
                dp[now_node][now_fuel + 1] = now_cost + cost[now_node];
                pq.push({now_cost + cost[now_node], now_node, now_fuel+1});
            }

            for (auto [to_node, to_dis] : g[now_node]) if (now_fuel >= to_dis && now_cost < dp[to_node][now_fuel - to_dis]) { // 如果目前的汽油量可以前往下一個節點 && 目前此 pq 元素紀錄的路徑總花費比之前紀錄的路徑最小總花費還便宜，就覆蓋
                dp[to_node][now_fuel - to_dis] = now_cost;
                pq.push({now_cost, to_node, now_fuel - to_dis});
            }
        }

        int ans = *min_element(all(dp[ed]));
        ans == INF && cout << "impossible\n" || cout << ans << '\n';
    }
}