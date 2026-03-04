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
    ifstream f("./onered.bmp", ios::binary);
    
    int n = 8;
    vector<unsigned char> v(n);
    f.read(reinterpret_cast<char*>(v.data()), n);
    cout << hex << uppercase << setfill('0');
    for (int i = 0; i < n; i++) cout << setw(2) << (int)v[i] << ' ';
    cout << '\n' << dec;
}
