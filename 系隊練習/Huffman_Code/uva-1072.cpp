#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define fi first
#define se second
#define INF LONG_LONG_MAX/1000
#define WA() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define all(x) (x).begin(), (x).end()
#define sz(x) ((int)(x).size())
#define int long long
#define PII pair<int, int>

bool cmp(string a, string b) { // 先看編碼長度，再看編碼字典序大小 (用於由上往下進行 dfs，且先枚舉右子節點)
    if (a.size() != b.size()) return a.size() < b.size();
    return a > b;
}

int cnt, n, t = 0;
vector<int> freq; // 紀錄第 x 個節點的頻率
vector<string> code; // 紀錄第 x 個節點的編碼
set<string, decltype(&cmp)> st(&cmp); // 紀錄所有的節點，並按照編碼的相關性排序

int findidx(string s) { // 因為 set 不支持隨機訪問，因此用 distance() 找出字串在 set 中的為第幾順位
    return distance(st.begin(), st.find(s));
}

void dfs(int x) {
    if (x && (!freq[x] || freq[x-1] < freq[x])) return; // 剪枝，判斷 k 是不是根結點，且該節點的頻率為 0，或是右子節點的頻率小於左子節點，皆不符合條件
    if (x == n) return void(cnt++); // 直到索引值推到 node.size() - 1，代表所有節點都找到適合的頻率，搜尋完畢
    string parent = code[x].substr(0, code[x].size()-1); // x 的父節點為 x 的前綴
    if (code[x+1][code[x+1].size()-1] == '0') freq[x+1] = freq[findidx(parent)] - freq[x], dfs(x+1); // 如果 x+1 為左子節點，則左子節點頻率 = 父節點頻率 - 右子節點頻率，且繼續往下搜尋
    else for (int i = freq[x]; i >= freq[x] - freq[x]/2; i--) freq[x+1] = i, dfs(x+1); // 否則 x + 1 則為右子節點，則需要在維持右子節點一定大於父節點的一半 (右子節點 > 左子節點) 的範圍下枚舉頻率，且繼續往下搜尋
}

signed main() { WA();
    string s; 
    while (cin >> n, n) {
        cnt = 0;
        st.clear();
        freq.clear();
        code.clear();
        while (n--) {
            cin >> s;
            for (int i = 0; i <= s.size(); i++) st.insert(s.substr(0, i)); // 將所有編碼的前綴放入 set，記錄下樹裡的所有節點
        }

        n = st.size() - 1; // 減去根節點
        freq.assign(n + 1, 0); freq[0] = 100; // 跟節點索引值為 0，頻率為全部的總和 100
        for (auto i : st) code.pb(i); // 方便之後以編碼頻率 (freq 的索引值)，訪問編碼字串
        dfs(0); // 從根節點往下搜尋
        cout << "Case " << ++t << ": " << cnt << '\n';
    }
}