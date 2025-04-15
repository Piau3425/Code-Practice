#include <bits/stdc++.h>
using namespace std;
#define int long long

vector<int> p(1000000, 1), v;

bool check(int x) {
    int sum = 0;
    while (x) {
        sum += x%10;
        x /= 10;
    }
    return p[sum];
}

signed main() { ios::sync_with_stdio(0); cin.tie(0);
    int n;
    unordered_set<int> s;
    p[0] = 0; p[1] = 1;
    for (int i = 2; i < 1000000; i++) if (p[i]) {
        for (int j = i*i; j < 1000000; j += i) p[j] = 0;
        s.insert(i);
    }
    for (auto i : s) if (check(i)) v.push_back(i);
    sort(v.begin(), v.end());
    for (cin >> n; n; n--) {
        int a, b;
        cin >> a >> b;
        cout << upper_bound(v.begin(), v.end(), b) - lower_bound(v.begin(), v.end(), a) << '\n';
    }
}