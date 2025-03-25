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
    int a, b;
    while (cin >> a >> b) {
        string ans = ".(0)";

        if (a%b) {
            map<int, int> mp;
            ans = ".";
            int div = a/b, mod = a%b, now = 1;
            while (!mp[mod]) {
                mod *= 10;
                mp[mod] = now++;
                ans += 
            }
        }


    }
}