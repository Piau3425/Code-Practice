#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second
#define WA() cin.tie(0)->sync_with_stdio(0)
#define all(x) (x).begin(), (x).end()
#define int long long
#define PII pair<int, int>
#define TIIS tuple<int, int, set<int>>
#define EMPTY (n-1) % (k-1)

signed main() { WA();
    int n, k; cin >> n >> k;
    vector<PII> v(n); // [索引值] = {編碼長度, 出現次數}
    priority_queue<TIIS, vector<TIIS>, greater<TIIS>> pq; // 出現次數總和 : 合併次數 : 索引值表
    for (auto &i : v) {
        cin >> i.se;
        pq.push({i.se, 0, set<int>{&i-&v.front()}});
    }
    if (EMPTY) for (int i = 0; i < k-1-EMPTY; i++) pq.push({0, 0, set<int>{}}); // 補足缺少的節點

    while (pq.size() > 1) {
        int cntsum = 0, weightsum = 0; set<int> idxall;
        for (int i = 0; i < k; i++) {
            auto [cnt, weight, idxlst] = pq.top(); pq.pop();
            cntsum += cnt, weightsum += weight;
            idxall.insert(idxlst.begin(), idxlst.end());
            for (auto idx : idxlst) v[idx].fi++;
        }
        pq.push({cntsum, weightsum+1, idxall});
    }

    int sum = 0;
    for (auto i : v) sum += i.fi*i.se;
    cout << sum << '\n' << max_element(all(v))->fi << '\n';
}