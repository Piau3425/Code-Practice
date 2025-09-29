#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define fi first
#define se second
#define INF 0x3f3f3f3f
#define WA() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define all(x) (x).begin(), (x).end()
#define sz(x) ((int)(x).size())
#define int long long

signed main() { WA();
    int n;
    cout << "PERFECTION OUTPUT\n";
    while (cin >> n, n) {
        int sum = 0;
        cout << setw(5) << n << "  ";
        for (int i = 1; i < n; i++) if (!(n%i)) sum += i;
        if (sum == n) cout << "PERFECT\n";
        else if (sum < n) cout << "DEFICIENT\n";
        else cout << "ABUNDANT\n";
    }
    cout << "END OF OUTPUT\n";
}