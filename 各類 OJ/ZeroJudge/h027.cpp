#include <bits/stdc++.h>
using namespace std;

int main(){
    int s, t, n, m, r, asum = 0, bsum, diff, mn = 1e9, count = 0;
    bool flag;
    cin >> s >> t >> n >> m >> r;
    vector<vector<int>> a(s, vector<int>(t)), b(n, vector<int>(m));

    for (auto &i : a) for(auto &j : i) cin >> j;
    for (auto &i : b) for(auto &j : i) cin >> j;
            
    for (auto i : a) for (auto j : i) asum += j;
	
    for (int i = 0; i + s - 1 < n; i++)
        for (int j = 0; j + t - 1 < m; j++) {
            bsum = 0; flag = true; diff = 0;
            for (int k = i; flag && k < i + s; k++)
                for (int h = j; flag && h < j + t; h++) {
                    if (a[k-i][h-j] - b[k][h]) {
                        diff++;
                        if(diff > r) flag = false;
                    }
                    bsum += b[k][h];
                }

            if(flag){
                count++;
                mn = min(abs(asum - bsum), mn);
            }
        }

	if (mn == 1e9) mn = -1;
    cout << count << '\n' << mn;
}