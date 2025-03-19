#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define int long long
#define 下一個是否為左子節點 (tree[k+1][tree[k+1].size()-1] == '0')
#define k節點的父節點字串 (tree[k].substr(0, tree[k].size()-1))

int Len = 0, ans = 0;
vector<string> tree;
vector<int> sim; // 每個節點的頻率
map<string, int> Map; // 各前綴在 node 裡的順序編號，同時也是 sim 的索引值

void dfs(int k) {
	if(k && (sim[k]<=0 || sim[k-1]<sim[k])) return; // 剪枝，k != 0 為不是根結點，且該節點的頻率為負或是較大編碼的頻率比較小的編碼小，皆不符合條件
	if(k == Len) return void(ans++); 
	if(下一個是否為左子節點 && sim[k]) // 且判斷左子節點的頻率是否為正
		sim[k+1] = sim[Map[k節點的父節點字串]] - sim[k], dfs(k+1); // 右子節點的頻率 = 父節點的頻率 - 左子節點的頻率
	else for(int i = sim[k]; i >= sim[k] - sim[k]/2; i--) sim[k+1] = i, dfs(k+1); // 如果 k 為右子節點，則枚舉所有維持右子節點頻率會大於左子節點的頻率
}

bool cmp(string a, string b) {
	if (a.size() == b.size()) return a > b;
	return a.size() < b.size();
}

signed main() {
	int n, Cas=0;
	while (cin >> n && n) {
		string s;
		set<string, decltype(&cmp)> node(&cmp); // 由頻率大到小，儲存所有出現的編碼的前綴
		for(int i = 0; i < n; i++) {
            cin >> s; node.insert(s);
			for (int j = 0; j <= s.size(); j++) node.insert(s.substr(0, j)); // 放入所有前綴
		}
		
		Len = node.size() - 1, ans = 0;
		int tmp = 0;
		tree = vector<string>();
		sim = vector<int>(Len+1, 0);
		sim[0] = 100; // sim[0] 為根結點，該出現頻率為所有節點的總和 = 100
		Map.clear();
		for (auto v : node) tree.pb(v), Map[v] = tmp++;
		dfs(0);
		cout << "Case " << ++Cas << ": " << ans << endl;	
	}
}