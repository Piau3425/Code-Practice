#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    
    while (t--) {
        bool f = false;
        stack<char> s;
        string str, l = "([{<", r = ")]}>";

        cin >> str;
        for (auto c : str) {
            if (l.find(c) != string::npos) s.push(c);
            else if (s.size() && l.find(s.top()) == r.find(c)) s.pop();
            else f = true;
        }
        if (s.size() || f) cout << "N\n";
        else cout << "Y\n";
    }
}