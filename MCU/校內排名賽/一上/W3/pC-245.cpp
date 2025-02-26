#include <bits/stdc++.h>
using namespace std;

int main() {
    string s;
    deque<string> dq;

    while (getline(cin, s)) {
        string word = "";
        for (int i = 0; i < s.size(); i++) {
            char c = s[i];
            if (isdigit(c)) {
                int n = c-'0';
                while (++i < s.size() && isdigit(s[i])) n = n*10+s[i]-'0';
                i--;
                if (!n) return 0;
                else {
                    string tmp = dq[n-1];
                    cout << tmp;
                    dq.erase(dq.begin()+n-1);
                    dq.push_front(tmp);
                }
            }
            else {
                cout << c;
                if (!isalpha(c)) {
                    if (word.empty()) continue;
                    dq.push_front(word);
                    word = "";
                }
                else word += c;
            }
        }
        if (word.size()) dq.push_front(word);
        cout << '\n';
    }
}