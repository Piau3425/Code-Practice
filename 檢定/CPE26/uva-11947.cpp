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

vector<int> vm = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
int ya(int x) {
    if (!(x%4)&&(x%100)||!(x%400)) return 1;
    return 0;
}

vector<string> star = {"capricorn", "aquarius", "pisces", "aries", "taurus", "gemini", "cancer", "leo", "virgo", "libra", "scorpio", "sagittarius"};
vector<int> k = {21, 20, 21, 21, 22, 22, 23, 22, 24, 24, 23, 23};

signed main() { WA();
    int t = 1, T; for (cin >> T; t <= T; t++) {
        string s; cin >> s;
        int m = stoi(s.substr(0, 2)), d = stoi(s.substr(2, 2)), y = stoi(s.substr(4));
        d += 280;
        while (d > vm[m]+((m==2)*ya(y))) {
            d -= vm[m]+((m==2)*ya(y));
            m++;
            if (m > 12) {
                m = 1;
                y++;
            }
        }
        cout << t << ' ' << setfill('0') << setw(2) << m << '/' << setfill('0') << setw(2) << d << '/' << y << ' ' << star[(m-1+(d >= k[m-1]))%12] << '\n';
    }
}