#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main() {
int t, T = 1; for (cin >> t; T <= t; T++) { cout << "Case " << T << ": ";
    string s; cin >> s;
    multiset<int> st;
    int sum = 0;
    for (auto &c : s) {
        sum += c-'0';
        st.insert(c-'0');
    }
    int cnt = 0;
    while (sum%3) {
        int flag = 0;
        for (int i = sum%3; i <= 9; i += 3) if (st.count(i)) {
            st.erase(st.find(i));
            sum -= i;
            flag = 1;
            break;
        }
        if (flag) cnt++;
        else break;
    }
    cout << (((cnt&1)+st.count(3)+st.count(6)+st.count(9))&1 ? 'S' : 'T') << '\n';
}
}