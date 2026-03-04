#include <bits/stdc++.h>
using namespace std;

#define all(x) (x).begin(), (x).end()
#define int long long

signed main() { 
    cin.tie(0)->sync_with_stdio(0);
    int T = 0;
    for (int n; cin >> n, n;) { 
        cout << "Case " << ++T << ": ";
        vector<string> v(n);
        for (auto &i : v) cin >> i;
        sort(all(v));
        
        int cnt = 0;
        for (auto it = v.begin(); it != prev(v.end()); it++) {
            string s = *it;
            auto last = v.end(); 
            
            for (int i = 0; i < s.size(); i++) {
                auto fd = upper_bound(it + 1, last, s.substr(0, i + 1), [](string a, string b){
                    return a < b.substr(0, a.size());
                });
                cnt += (last - fd) * (i * 2 + 1);
                
                last = fd;
                if (last == it + 1) break; // 沒人跟 s 一樣長這樣了
            }
            
            if (last > it + 1) {
                int len = s.size();
                for (auto p = it + 1; p != last; p++) {
                    if (p->size() == len) {
                        // 完全相同: 2 * len (chars) + 2 (nulls)
                        cnt += (len * 2 + 2);
                    } else {
                        // Superstring: 2 * len (chars) + 1 (null mismatch)
                        cnt += (len * 2 + 1);
                    }
                }
            }
        }
        cout << cnt << "\n";
    }
}