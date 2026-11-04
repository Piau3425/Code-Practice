#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;

#define pb push_back
#define fi first
#define se second
#define INF LONG_LONG_MAX/1000
#define WA() cin.tie(0)->sync_with_stdio(0)
#define all(x) (x).begin(), (x).end()
#define int long long
#define PII pair<int, int>
#define TIII tuple<int, int, int>

template<typename T>
using rbtree = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

bool leap(int x) {
    return !(x%4)&&(x%100)||!(x%400);
}



signed main() { WA();
    int t, cas = 0; for (cin >> t, cin.ignore(); t--;) {
        string s; getline(cin, s);
        stringstream ss(s);
        vector<string> m2n = {"January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};
        int y, m, d;
        getline(ss, s, '-'); y = stoi(s);
        getline(ss, s, '-'); m = find(all(m2n), s)-m2n.begin();
        getline(ss, s, '-'); d = stoi(s);
        
        vector<int> m2d = {31, leap(y) ? 29 : 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
        int n; cin >> n; cin.ignore(); d += n;
        while (d > m2d[m]) {
            d -= m2d[m];
            m++;
            if (m == 12) {
                m = 0;
                y++;
                m2d[1] = leap(y) ? 29 : 28;
            }
        }
        cout << "Case " << ++cas << ": " << y << '-' << m2n[m] << '-' << setfill('0') << setw(2) << d << '\n';
    }
}