#include <bits/stdc++.h>
using namespace std;

#define INF LONG_LONG_MAX/1000
#define WA() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define all(x) (x).begin(), (x).end()

int main() { WA();
    int n;
    while (cin >> n, n >= 3) {
        vector<double> x(n), y(n);
        int tr;
        double tx = -INF;
        for (int i = 0; i < n; i++) {
            cin >> x[i] >> y[i];
            if (x[i] > tx) tx = x[i], tr = i; // 找出最右邊的點
        }
        
        double mx = 0, mn = 360, deg;
        for (int i = 0; i < n; i++) {
            double l = (i+(n-1))%n, r = (i+1)%n, xa = x[l] - x[i], xb = x[r] - x[i], ya = y[l] - y[i], yb = y[r] - y[i];
            deg = acos((xa*xb+ya*yb) / (sqrt(xa*xa+ya*ya) * sqrt(xb*xb+yb*yb))) / acos(-1)*180; // 兩向量求夾角
            if (yb*xa-ya*xb > 0 != (y[(tr+1)%n]-y[tr])*(x[(tr+(n-1))%n]-x[tr])-(y[(tr+(n-1))%n]-y[tr])*(x[(tr+1)%n]-x[tr]) > 0) deg = 360 - deg; // 用兩外積判斷哪側為圖的內部
            mx = max(mx, deg); mn = min(mn, deg);
        }
        
        cout << fixed << setprecision(6) << min(mn, mx) << ' ' << fixed << setprecision(6) << max(mn, mx) << '\n';
    }
}