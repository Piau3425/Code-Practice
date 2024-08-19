#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    char c;
    vector<int> ds, len;
    cin >> n;
    while (cin >> c) ds.push_back((c >= 'a'));

    int last = ds[0], con = 0;
    for (auto i : ds) {
        if (i == last) con++;
        else {
            len.push_back(con);
            con = 1;
        }
        last = i;
    }
    len.push_back(con);

    /*
    for (auto i : len) cout << i << ' ';
    cout << '\n';
    */

    int cnt = 0, ans = 0;
    for (int i = 0; i < len.size(); i++) {
        if (len[i] == n) cnt++;
        else {
            if ((i-cnt-1 >= 0) && len[i-cnt-1] > n) cnt++;
            if (len[i] > n) cnt++;
            ans = max(cnt, ans);
            cnt = 0;
        }
    }

    cout << ans*n;
}