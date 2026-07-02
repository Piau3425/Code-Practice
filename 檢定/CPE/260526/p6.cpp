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

int pic[32][32], idx, cnt;

void f(string &s, int r, int c, int w) {
    if (s[idx++] == 'p') {
        f(s, r, c, w/2);     f(s, r, c+w/2, w/2);      //2   1
        f(s, r+w/2, c, w/2); f(s, r+w/2, c+w/2, w/2);  //3   4
    }
    else if (s[idx-1] == 'f') for (int i = r; i < r+w; i++) for (int j = c; j < c+w; j++) if (!~pic[i][j]++) cnt++;
}

signed main() { WA();
    int t; for (cin >> t; t--;) {
        string a, b; cin >> a >> b;
        cnt = 0;
        memset(pic, -1, sizeof(pic));
        idx = 0; f(a, 0, 0, 32);
        idx = 0; f(b, 0, 0, 32);
        cout << "There are " << cnt << " black pixels.\n";
    }
}