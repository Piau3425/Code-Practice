#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main() { 
    int n;
    for (cin >> n; n; n--) {
        int t, sum = 0;
        cin >> t;
        vector<int> v(t);
        for (auto &i : v) cin >> i;
        sort(v.begin(), v.end(), greater<int>());
        int per[4] = {ceil(t*0.1), ceil(t*0.3), ceil(t*0.6), ceil(t*0.8)};
        for (auto i : v) {
            int rank = find(v.begin(), v.end(), i) - v.begin();
            for (int j = 0; j < 4; j++) {
                if (rank < per[j]) {
                    sum += i*(0.4-j*0.1);
                    break;
                }
            }
        }
        cout << sum << '\n';
    }
}