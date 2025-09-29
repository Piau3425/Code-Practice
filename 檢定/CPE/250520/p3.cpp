#include <bits/stdc++.h>
using namespace std;

vector<int> v, ans;

void f(int x) {
    if (ans.size() == 6) {
        for (auto &i : ans) cout << i << " \n"[&i == &ans.back()];
        return;
    }
    if (x == v.size()) return;

    ans.push_back(v[x]);
    f(x+1);
    ans.pop_back();
    f(x+1);
}

int main() {
    int n, T = 0;
    while (cin >> n, n) {
        if (T++) cout << '\n';
        v.assign(n, 0);
        for (auto &i : v) cin >> i;
        f(0);
    }
}