#include <bits/stdc++.h>
using namespace std;

int main() {
    int r, c, m;
    cin >> r >> c >> m;
    vector<vector<int>> v(r, vector<int>(c));
    for (auto &a : v) for (auto &b : a) cin >> b;
    vector<int> n(m);
    for (auto &i : n) cin >> i;
    
    while (m--) {
    	if (n[m]) {
            vector<vector<int>> nv = v;
            for (int i = 0; i < v.size(); i++)
                for (int j = 0; j < v[0].size(); j++)
                	v[i][j] = nv[nv.size()-1-i][j];
        }
        else {
            vector<vector<int>> nv(v[0].size(), vector<int>(v.size()));
            for (int i = 0; i < v.size(); i++)
                for (int j = 0; j < v[0].size(); j++)
                	nv[nv.size()-1-j][i] = v[i][j];
                v = nv;
        }
    }
    
	cout << v.size() << ' ' << v[0].size() << '\n';
    for (auto a : v) 
        for (int i = 0; i < a.size(); i++) cout << a[i] << " \n"[i+1 == a.size()];
}