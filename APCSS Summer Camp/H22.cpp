#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    deque<char> s, t(m);
    vector<string> e(n);
    for (auto &str : e) cin >> str;
    for (auto &c : t) cin >> c;

    reverse(e.begin(), e.end());
    for (auto k : e) {
        reverse(k.begin(), k.end());
        for (int i = 0; i < k.size(); i++) {
            if (k[i]-'0') {
                s.push_back(t[t.size()-1]);
                t.erase(t.end()-1);
            }
            else {
                s.push_front(t[t.size()-1]);
                t.erase(t.end()-1);
            }
            /*
            cout << "s = ";
            for (auto c : s) cout << c;
            cout <<  " t = ";
            for (auto c : t) cout << c;
            cout << '\n';
            */
        }
        
        int cnt = 0;
        for (auto i : k) if (i-'0') cnt++;
        if (cnt&1) {
            deque<char> tmp(s.begin() + s.size()/2 + (s.size()&1), s.end());
            if (s.size()&1) tmp.push_back(s[s.size()/2]);
            tmp.insert(tmp.end(), s.begin(), s.begin() + s.size()/2);
            s = tmp;
        }
        /*
        cout << "s = ";
        for (auto c : s) cout << c;
        cout << '\n';
        */
        t = s; s.clear();
    }

    for (auto c : t) cout << c;
}