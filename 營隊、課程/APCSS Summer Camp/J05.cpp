#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, time = 0, ans = 0;
    map<int, int> mp; // mp[end] = start;
    cin >> n;
    while (n--) {
        int start, end;
        cin >> start >> end;
        if ((!mp.count(end) || mp[end] < start)) {
            mp[end] = start;
        }
    }

    for (auto i : mp) {
        if (time <= i.second) {
            time = i.first;
            ans++;
        }
    }

    cout << ans;
}