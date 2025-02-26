#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define fi first
#define se second
#define INF LONG_LONG_MAX/1000
#define WA() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define all(x) (x).begin(), (x).end()
#define sz(x) ((int)(x).size())
#define int long long
#define PII pair<int, int>

signed main() { WA();
    int m2d[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}, n;
    string s[] = {"Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday", "Sunday"};
    cin >> n;
    while (n--) {
        int m, d;
        cin >> m >> d;
        for (int i = 0; i < m-1; i++) d += m2d[i];
        cout << s[(d+4)%7] << '\n';
    }
}