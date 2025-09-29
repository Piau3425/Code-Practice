#include <bits/stdc++.h>
using namespace std;

void f(int range, int length, vector<int> &save) {
    if (save.size() == length) {
        for (int i = 0; i < save.size(); i++) cout << (i ? " " : "") << save[i];
        cout << '\n';
        return;
    }
    for (int i = 1; i <= range; i++) {
        if (find(save.begin(), save.end(), i) != save.end()) continue;
        save.push_back(i);
        f(range, length, save);
        save.pop_back();
    }
}

int main() {
    int n, k;
    cin >> n >> k;
    vector<int> v;
    f(n, k, v);
}