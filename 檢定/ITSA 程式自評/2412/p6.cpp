#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define fi first
#define se second
#define INF 0x3f3f3f3f
#define WA() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define all(x) (x).begin(), (x).end()
#define sz(x) ((int)(x).size())


int main() { WA();
    int n, a = 1, b, c, d, e; // 種子 芽 花 花1 花2
    b = c = d = e = 0;
    cin >> n;
    while (n--) {
        e = d;
        d = c;
        c = b;
        b = a;
        a = d + e;
    }
    cout << c + d;
}