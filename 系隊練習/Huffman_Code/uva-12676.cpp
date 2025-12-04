#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define INF LONG_LONG_MAX/1000
#define WA() cin.tie(0)->sync_with_stdio(0)
#define all(x) (x).begin(), (x).end()
#define int long long

signed main() { WA();
    int n;
    while (cin >> n) {
        multiset<int> st;
        int mx = -1e9, t;
        while (n--) {
            cin >> t; // 輸入編碼長度
            st.insert(t); // 紀錄樹中每層有幾個節點
            mx = max(mx, t); // 找出樹為幾層
        }
        vector<priority_queue<int, vector<int>, greater<int>>> g(mx+1); // g[層數] = 該層的節點表 (pq)，存各節點的字串長度
        int last = 1; // 求最短字串長度，所以預設第 0 層 (最底層) 的節點只紀錄一個字元
        for (int depth = 0; depth < mx; depth++) { // 從最底層開始往上爬
            for (int i = st.count(mx-depth); i; i--) g[depth].push(last); // 放入原有的節點數，並且節點紀錄的字串長度依照求最短長度來看，最短長度會是下一層中的最大長度  
            while (g[depth].size()) { // 合併當前層的所有節點，若沒有可合併的對象則直接往上放
                int sum = 0;
                for (int i = 0, m = min(2LL, (int)g[depth].size()); i < m; i++) sum += last = g[depth].top(), g[depth].pop();
                g[depth+1].push(sum);
            }
        }

        cout << g[mx].top() << '\n';
    }
}