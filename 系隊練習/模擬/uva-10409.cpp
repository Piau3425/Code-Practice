#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define fi first
#define se second
#define INF LONG_LONG_MAX/1000
#define WA() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define all(x) (x).begin(), (x).end()
#define int long long
#define PII pair<int, int>

signed main() { WA();
    int n; while (cin >> n, n) {
        deque<int> v = {1, 5, 6, 2, 3, 4}; // 中心圈, 左右
        while (n--) {
            string s; cin >> s;
            if (s[0] == 'n') v.insert(v.begin() + 4, v.front()), v.pop_front();
            if (s[0] == 's') v.insert(v.begin(), v[3]), v.erase(v.begin()+4);
            if (s[0] == 'e') {
                int tmp = v[0];
                v[0] = v[4];
                v[4] = v[2];
                v[2] = v[5];
                v[5] = tmp;
            }
            if (s[0] == 'w') {
                int tmp = v[0];
                v[0] = v[5];
                v[5] = v[2];
                v[2] = v[4];
                v[4] = tmp;
            }
        }
        cout << v[0] << '\n';
    }
}