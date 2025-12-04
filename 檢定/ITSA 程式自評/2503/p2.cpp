#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second
#define WA() cin.tie(0)->sync_with_stdio(0)
#define all(x) (x).begin(), (x).end()
#define int long long

signed main() { WA();
    // 1. 紀錄所有城市擁有的屬性
    int n, ck; cin >> n; cin.ignore();
    string s, k, cty;
    map<string, set<string>> mp; // 城市名：屬性表
    vector<pair<string, bool>> v(n); // 紀錄城市和查詢結果，用於最後依照城市的輸入順序輸出
    for (int i = 0; i < n; i++) {
        getline(cin, s);
        stringstream ss(s); ss >> cty;
        while (ss >> s) mp[cty].insert(s); // 儲存城市對應的屬性到屬性表 (set)
        v[i].fi = cty; // 紀錄城市的名字
    }

    cin >> n; cin.ignore();
    while (n--) {
        for (auto &i : v) i.se = 0; // 清除上次查詢的結果
        // 2. 讀取查詢文字中，並從中取出各項條件
        getline(cin, s);
        stringstream ss(s);
        while (getline(ss, s, '+')) { // 取出以 "或" 區隔的查詢
            // 3. 枚舉每個城市有無符合查詢條件
            for (auto &[cty, isnot] : v) {
                ck = 1;
                stringstream lst(s); // 查詢的屬性
                while (lst >> k) !mp[cty].count(k) && (ck = 0); // 如果該城市查詢不到的其屬性，就不成立
                ck && (isnot = 1); // 如果該城市符合條件，將其標記
            }
        }

        // 4. 輸出符合條件的城市
        ck = 0;
        for (auto [cty, isnot] : v) isnot && cout << (ck++ ? " " : "") << cty; // 輸出被標記的城市
        (ck && cout << "\n") || cout << "None\n"; // 若上行程式碼沒有進行輸出，則輸出 "None"
    }
}