#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define fi first
#define se second
#define INF LONG_LONG_MAX/1000
#define WA() cin.tie(0)->sync_with_stdio(0)
#define all(x) (x).begin(), (x).end()
#define int long long
#define PII pair<int, int>

signed main() { WA();
    string pa; int T = 0;
    while (getline(cin, pa)) {
        vector<string> ans;
        string text;
        while (getline(cin, text) && text.size()) {
            if (pa.find('*') == string::npos) {
                if (pa == text) ans.pb(text);
                continue;
            }
            string dupa = pa;
            int prefix = 0, suffix = dupa.size()-1, flag = 0;
            while (dupa[prefix] != '*' && dupa[prefix] == text[prefix]) prefix++;
            while (dupa[suffix] != '*' && dupa[suffix] == text[text.size() - (dupa.size()-suffix)]) suffix--;
            //cout << prefix << ' ' << suffix << '\n';
            if (dupa[prefix] == '*' && dupa[suffix] == '*') dupa = dupa.substr(prefix, suffix-prefix+1);
            else continue;
            stringstream sspa(dupa);
            string dupt = text;
            flag = 1;
            while (getline(sspa, dupa, '*')) {
                if (dupa.empty()) continue;
                //cout << dupa << ' ';
                if (flag) flag = 0;
                else break;
                string m = dupa + "\x01" + text;
                int n = m.size();
                vector<int> p(n);
                for (int i = 1; i < n; i++) {
                    int j = p[i-1];
                    while (j > 0 && m[i] != m[j]) j = p[j-1];
                    p[i] = j + (m[i] == m[j]);
                    if (p[i] == dupa.size()) {
                        text = m.substr(i+1);
                        flag = 1;
                        break;
                    }
                }
            }
            if (flag) ans.pb(dupt);
        }
        if (ans.size()) {
            if (T++) cout << '\n';
            cout << "MATCHES FOR THE PATTERN: " << pa << '\n';
            for (auto &i : ans) cout << i << '\n';
        }
    }
}