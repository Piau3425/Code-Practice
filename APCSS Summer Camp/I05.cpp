#include <bits/stdc++.h>
using namespace std;

unordered_map<int, int> dp;

int f(int n) {
    if (dp[n]) return dp[n];
    if (n == 0) return 0;
    return dp[n] = n + f(n - 1);
}

int main() {
    int n, x, ans = 0;
    cin >> n >> x;
    vector<int> v(n);
    unordered_map<int, int> mp;
    
    for (auto &i : v) cin >> i;

    int ldx = 0, rdx = 0;
    
    for (; rdx <= v.size(); rdx++) {

        mp[v[rdx]]++;

        if (mp.size() <= x) continue;

        //*
        for (int i = ldx; i < rdx; i++) cout << v[i] << ' ';
        cout << "/ " << ldx << ' ' << rdx-1 << '\n';
        //*/

        cout << f(rdx-1 - ldx + 1) << '\n';
        ans += f(rdx-1 - ldx + 1);

        while (mp.size() > x) {
            mp[v[ldx]]--;
            if (!mp[v[ldx]]) mp.erase(v[ldx]);
            ldx++;
        }
    } 
    

    cout << ans;
}