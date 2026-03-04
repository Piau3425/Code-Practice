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
    vector<vector<double>> v = {
        {0.10, 0.06, 0.02},
        {0.25, 0.15, 0.05},
        {0.53, 0.33, 0.13},
        {0.87, 0.47, 0.17},
        {1.44, 0.80, 0.30}
    };
    char ch; while (cin >> ch, ch != '#') {
        string s; int sh, sm, eh, em, a, b, c; a = b = c = 0;
        cin >> s >> sh >> sm >> eh >> em;
        sm = sm + sh*60, em = em + eh*60;
        if (sm == em) a = 600, b = 240, c = 600;
        else for (; sm != em; sm = (sm+1)%1440) {
            if (sm >= 8*60 && sm < 18*60) a++;
            else if (sm >= 18*60 && sm < 22*60) b++;
            else c++;
        }
        cout << setw(10) << s << setw(6) << a << setw(6) << b << setw(6) << c << setw(3) << ch << setw(8) << fixed << setprecision(2) << v[ch-'A'][0]*a + v[ch-'A'][1]*b + v[ch-'A'][2]*c << "\n";
    }
}