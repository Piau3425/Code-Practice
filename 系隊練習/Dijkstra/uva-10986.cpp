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
    int T; cin >> T; // 測資數量
    for (int k = 1; k <= T; k++) {
        cout << "Case #" << k << ": "; // 題目要求的輸出格式

        int n, m, s, t; cin >> n >> m >> s >> t; // 題目輸入，n: 節點數，m: 邊數，s: 起點，t: 終點

        vector<vector<PII>> g(n); // 鄰接串列，g[u] 儲存所有從 u 可以到達的節點(first)跟權重(second)
        vector<int> dis(n, INF); // Dijkstra Algorithm 的距離陣列，dis[i] 代表目前已知從 s 到 i 的最短距離

        while (m--) {
            int a, b, w;
            cin >> a >> b >> w; // a 與 b 節點之間有一條權重為 w 的無向邊
            g[a].pb({b, w}); // 用兩個有向邊
            g[b].pb({a, w}); // 來實現無向邊的效果
        }

        // priority_queue 存 {目前距離, 節點編號}
        // 使用 min Heap 讓距離較小的狀態優先被取出
        priority_queue<PII, vector<PII>, greater<PII>> pq;
        
        dis[s] = 0; //起點的到自己的距離是 0
        pq.push({0, s}); // 從起點開始進行 Dijkstra

        while (pq.size()) {
            auto [nowDist, nowID] = pq.top(); pq.pop(); // 取出目前距離最短的候選狀態
            
            // 若 now 已經比目前記錄的最短距離大
            // 這代表已經有比 now 更短的狀態跑過了，已經沒有更新的價值，可跳過
            if (nowDist > dis[nowID]) continue;

            // 檢查 now 所有相鄰邊，更新以 now 到鄰居節點的最短距離
            for (auto [toID, toDist] : g[nowID]) {
                if (dis[toID] > dis[nowID] + toDist) {
                    dis[toID] = dis[nowID] + toDist; // 找到更短的路徑，更新距離
                    pq.push({dis[toID], toID}); // 將新的距離狀態放入 priority_queue
                }
            }
        }

        if (dis[t] == INF) cout << "unreachable\n"; // 如果依舊是 INF，t 沒被更新過，代表從 s 走不到 t
        else cout << dis[t] << '\n'; // 輸出 s 到 t 的最短距離
    }
}