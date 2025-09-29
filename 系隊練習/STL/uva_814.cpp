#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define fi first
#define se second
#define INF LONG_LONG_MAX/1000
#define WA() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define all(x) (x).begin(), (x).end()
#define int long long
#define PII pair<int, int>
#define PSS pair<string, string>

signed main() { WA();
    string s;
    map<string, set<string>> mp;
    while (getline(cin, s), s != "*") {
        stringstream ss(s); ss >> s;
        string mta;
        ss >> mta;
        ss >> s;
        while (ss >> s) mp[mta].insert(s);
    }
    while (getline(cin, s), s != "*") {
        stringstream ss(s); ss >> s;
        string message;
        PSS sender;
        map<string, vector<string>> receiver;
        vector<string> order;
        stringstream sss(s);
        getline(sss, s, '@'); sender.fi = s;
        getline(sss, s, '@'); sender.se = s;
        while (ss >> s) {
            stringstream ssss(s);
            string a, b;
            getline(ssss, s, '@'); a = s;
            getline(ssss, s, '@'); b = s;
            if (find(all(receiver[b]), a) == receiver[b].end()) receiver[b].pb(a);
            if (find(all(order), b) == order.end()) order.pb(b);
        }
        getline(cin, s);
        while (getline(cin, s), s != "*") message += "     " + s + "\n";

        for (auto mta : order) {
            bool ck = 0;
            cout << "Connection between " << sender.se << " and " << mta << '\n';
            cout << "     HELO " << sender.se << "\n     250\n";
            cout << "     MAIL FROM:<" << sender.fi << "@" << sender.se << ">\n     250\n";
            for (auto i : receiver[mta]) {
                cout << "     RCPT TO:<" << i << "@" << mta << ">\n";
                if (mp[mta].count(i)) cout << "     250\n", ck = 1;
                else cout << "     550\n";
            }
            if (ck) cout << "     DATA\n     354\n" << message << "     .\n     250\n";
            cout << "     QUIT\n     221\n";
        }
    }
}