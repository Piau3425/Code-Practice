#include <bits/stdc++.h>
using namespace std;

#define WA() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define all(x) (x).begin(), (x).end()
#define int long long

signed main() {
    string a, b;
    while (getline(cin, a) && getline(cin, b)) {
        vector<int> va(26), vb(26);
        for (auto &c : a) va[c-'A']++;
        for (auto &c : b) vb[c-'A']++;
        sort(all(va)); sort(all(vb));
        for (int i = 0; i < 26; i++) if (va[i] != vb[i]) {
            cout << "NO\n";
            goto no;
        }
        cout << "YES\n";
        no:;
    }
}