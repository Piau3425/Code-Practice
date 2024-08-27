#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, room = -1e9;
    map<int, int> mp;
    cin >> n;
    while (n--) {
        int l, r;
        cin >> l >> r;
        mp[l]++;
        mp[r+1]--;
    }

    int prefix = 0;
    for (auto &i : mp) {
        prefix += i.second;
        room = max(room, prefix);
    }

    cout << room;

}