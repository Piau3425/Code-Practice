#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define fi first
#define se second
#define INF LONG_LONG_MAX/1000
#define WA() cin.tie(0)->sync_with_stdio(0)
#define all(x) (x).begin(), (x).end()
#define sz(x) ((int)(x).size())
#define int long long
#define PII pair<int, int>

signed main() { WA();
    int sum = 0; string num; char c;
    while (cin.get(c)) {
        if (isdigit(c)) num += c;
        else {
            if (num.size()) sum += stoi(string(num.rbegin(), num.rend()));
            num.clear();
        }
    }
    if (num.size()) sum += stoi(string(num.rbegin(), num.rend()));
    cout << sum << '\n';
}

/*
while (cin >> c) {
    if (c == '.') {
        if (num.size()) sum += stoi(string(num.rbegin(), num.rend()));
        cout << sum << '\n', sum = 0;
    }
    else if (isdigit(c)) num += c;
    else {
        if (num.size()) sum += stoi(string(num.rbegin(), num.rend()));
        num.clear();
    }
}
if (num.size()) sum += stoi(string(num.rbegin(), num.rend()));
cout << sum << '\n';
*/
/*
while (getline(cin, s)) {
    int sum = 0; string num;
    for (auto c : s) {
        if (isdigit(c)) num += c;
        else {
            if (num.size()) sum += stoi(string(num.rbegin(), num.rend()));
            num.clear();
        }
    }
    if (num.size()) sum += stoi(string(num.rbegin(), num.rend()));
}
cout << sum << '\n';
*/
/*
while (getline(cin, s)) {
    int sum = 0;
    for (auto &c : s) if (!isalnum(c)) c = ' ';
    stringstream ss(s);
    while (ss >> s) {
        int ck = 1;
        for (auto c : s) if (!isdigit(c)) ck = 0;
        if (ck) sum += stoi(string(s.rbegin(), s.rend()));
    }
    cout << sum << '\n';
}
*/