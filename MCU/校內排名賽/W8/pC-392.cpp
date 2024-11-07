#include <bits/stdc++.h>
using namespace std;
#define all(x) x.begin(), x.end()

int main() {
    vector<int> v(9);
    while (cin >> v[0]) {
        vector<string> ans;
        int idx = 8;
        for (int i = 1; i < 9; i++) cin >> v[i];
        reverse(all(v));

        for (int i = 8; i >= 0; i--) {
            if (v[i] == 0) continue;
            if (v[i] > 0) ans.push_back("+");
            else ans.push_back("-");
            if (i>1) ans.push_back((abs(v[i]) == 1 ? "" : to_string(abs(v[i]))) + "x^" + to_string(i));
            else if (i == 1) ans.push_back((abs(v[i]) == 1 ? "" : to_string(abs(v[i]))) + "x");
            else ans.push_back(to_string(abs(v[i])));
        }

        for (int i = 0; i < ans.size(); i++) {
            if (!i && ans[i] == "+") continue;
            if (i > 1) cout << " ";
            cout << ans[i];
        }
        if (ans.empty()) cout << 0;
        cout << '\n';
    }
}