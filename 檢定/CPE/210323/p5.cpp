#include <bits/stdc++.h>
using namespace std;
#define int long long
int cnt;
string K;
set<int> st;

bool prime(int n) {
    if (n < 2) return false;
    for (int i = 2; i*i <= n; i++) if (!(n%i)) return false;
    return true;
}

void f(string &s, int idx, int t) {
    if (idx == t) {
        if (s.size()) {
            string tmp = s;
            sort(tmp.begin(), tmp.end());
            do {
                int n = stoi(tmp);
                if (prime(n)) st.insert(n);
            } while (next_permutation(tmp.begin(), tmp.end()));
        }
        return;
    }

    s += K[idx];
    f(s, idx+1, t);
    s.pop_back();
    f(s, idx+1, t);

}

signed main() {
    int t; for (cin >> t; t--;) {
        cin >> K;
        cnt = 0;
        string gg;
        st.clear();
        f(gg, 0, K.size());
        cout << st.size() << '\n';
    }
}