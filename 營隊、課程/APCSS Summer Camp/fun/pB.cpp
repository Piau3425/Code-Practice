#include <bits/stdc++.h>
using namespace std;

int main() {
    string a, b;
    int n;
    for (cin >> n; n; n--) {
        cin >> a >> b;
        long long na = stoi(a.size() >= 9 ? a.substr(a.size() - 9) : a), nb = stoi(b.size() >= 9 ? b.substr(b.size() - 9) : b);
        cout << na*nb%1000000000 << '\n';
    }
}