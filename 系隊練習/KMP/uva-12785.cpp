#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define fi first
#define se second
#define INF LONG_LONG_MAX/1000
#define WA() cin.tie(0)->sync_with_stdio(0)
#define all(x) (x).begin(), (x).end()
#define int long long
#define PII pair<int, int>

signed main() { WA();
    int n;
    while (cin >> n) {
        string s, pa; cin >> s;
        while (n--) {
            string dup = s;
            cin >> pa;
            stringstream sspa(pa);
            int flag = 1;
            while (getline(sspa, pa, '*')) {
                if (pa.empty()) continue;
                if (flag) flag = 0;
                else break;
                string m = pa + "#" + dup;
                int k = m.size();
                vector<int> p(k);
                for (int i = 1; i < k; i++) {
                    int j = p[i-1];
                    while (j > 0 && m[i] != m[j]) j = p[j-1];
                    p[i] = j + (m[i] == m[j]);
                    if (p[i] == pa.size()) {
                        flag = 1;
                        dup = m.substr(i+1);
                        break;
                    }
                }
            }
            flag && cout << "yes\n" || cout << "no\n";
        }
    }
}