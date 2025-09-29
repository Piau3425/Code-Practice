#include <bits/stdc++.h>
using namespace std;

int main() {
    int a, b, n, sum = 0;
    cin >> a >> b >> n;
    while (n--) {
        int t;
        multiset<int> s;
        while (cin >> t && t) if (t > 0) s.insert(t); else s.erase(s.find(abs(t)));
        if (s.count(a) && s.count(b)) sum++;
    }

    cout << sum;
}