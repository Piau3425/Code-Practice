#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, mn = 1e9;
    string ans;
    cin >> n;
    while (n--) {
        string s;
        unordered_set<char> filter;
        cin >> s;
        for (auto c : s) filter.insert(c);
        if (filter.size() < mn || (filter.size() == mn && s < ans)) {
            ans = s;
            mn = filter.size();
        }
    }

    cout << ans;
}