#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second
#define WA() cin.tie(0)->sync_with_stdio(0)
#define int long long
#define all(x) (x).begin(), (x).end()
#define EMPTY (n-1) % (r-1)

signed main() { WA();
    int r, n, t = 0;
    while (cin >> r, r) {
        cin >> n;
        vector<pair<char, int>> v(n); // 紀錄字元出現的頻率
        for (int i = 0; i < n; i++) cin >> v[i].se, v[i].fi = char('A' + i);
        priority_queue<pair<int, string>, vector<pair<int, string>>, greater<pair<int, string>>> pq; // 頻率及該節點所有的字元
        map<char, string> huff; // 字元 (節點) 對應的編碼
        for (int i = 0; i < n; i++) pq.push({v[i].se, string(1, v[i].fi)}); // 將所有的字母以及其頻率放入 minheap
        if (EMPTY) for (int i = 0; i < r-1-EMPTY; i++) pq.push({0, "}"}); // n-1 必須為 r-1 的倍數，才能進行 n-1 次的合併 (直到剩下根節點)。而每次合併 r 個節點，總節點數會減少 r-1 個節點。
        //                                                     放入 }，是因為 } 的 ascii 大於所有的大寫字母，方便使虛擬字元在合併時被放在字串尾
        while (pq.size() > 1) { // 直到剩下根節點
            int nsum = 0; string ssum;
            for (int i = 0; i < r; i++) { // r 個節點一組合併
                auto [f, s] = pq.top(); pq.pop(); // 找出目前頻率最小的元素
                nsum += f; // 計算該組的頻率總和
                ssum += s; // 將該組的字元組合起來
                for (auto c : s) huff[c] = to_string(i) + huff[c]; // 為該分支的字典序第 i 個字元的編碼前面加上 i
            }
            sort(all(ssum)); // 維護字元在字串中的順序 (尤其是虛擬字元 '}')
            pq.push({nsum, ssum}); // 將合併完的結果放回 minheap
        }

        double w = 0, sum = 0;
        while (n--) w += huff[n+'A'].size()*v[n].se, sum += v[n].se; // (頻率*編碼長度)總和 / 頻率總和
        cout << "Set " << ++t << "; average length " << fixed << setprecision(2) << w/sum << '\n';
        for (auto [c, n] : v) cout << "    " << c << ": " << huff[c] << '\n'; // 按照格式輸出
        cout << '\n'; // 每筆測資皆需要換行分割
    }
}