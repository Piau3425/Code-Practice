/*
運算元在題目的定義中一定只會是一個字元
在此程式碼中，負號在 stack 中會被轉換成 "u-" 來方便處理
因此 weight 中的 "u-" 為 7
*/

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

unordered_map<string, int> weight = {
    {"!", 8}, {"u-", 8},
    {"^", 7},
    {"*", 6}, {"/", 6}, {"%", 6},
    {"+", 5}, {"-", 5},
    {"<", 4}, {"<=", 4}, {">", 4}, {">=", 4},
    {"==", 3}, {"!=", 3},
    {"&&", 2},
    {"||", 1},
    {"(", -1}
};

signed main() { WA();
    string input, output, token = "!-*/%+<=>^&|(", now;
    getline(cin, input);
    stack<string> sk;
    input.erase(remove(all(input), ' '), input.end());
    for (int i = 0; i < input.size(); i += now == "u-" ? 1 : now.size()) {
        int isOperator = 0;
        if (i+1 < input.size() && weight.find(input.substr(i, 2)) != weight.end()) now = input.substr(i, 2), isOperator = 1;
        else if (weight.find(input.substr(i, 1)) != weight.end()) now = input.substr(i, 1), isOperator = 1;
        else now = input.substr(i, 1);

        if (now == "(") sk.push(now);
        else if (now == ")") {
            while (sk.size() && sk.top() != "(") {
                if (sk.top() == "u-") output += "-";
                else output += sk.top();
                sk.pop();
            }
            if (sk.size()) sk.pop();
        }
        else if (isOperator) {
            if (now == "-" && (i == 0 || token.find(input[i-1]) != string::npos)) now = "u-";
            while (sk.size() && (weight[sk.top()] > weight[now] || (now != "^" && weight[sk.top()] == weight[now]))) {
                if (sk.top() == "u-") output += "-";
                else output += sk.top();
                sk.pop();
            }
            sk.push(now);
        }
        else output += now;
    }
    while (sk.size()) {
        if (sk.top() == "u-") output += "-";
        else output += sk.top();
        sk.pop();
    }
    cout << output;
}