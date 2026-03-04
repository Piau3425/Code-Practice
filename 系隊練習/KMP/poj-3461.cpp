#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n;
    for (cin >> n; n--;) {
        string s, r; cin >> s >> r;
        string t = s + "#" + r;
        int len = t.size(), cnt = 0;
        vector<int> p(len);
        for (int i = 1; i < len; i++) {
            int j = p[i-1];
            while (j > 0 && t[i] != t[j]) j = p[j-1];
            p[i] = j + (t[i] == t[j]);
            if (p[i] >= s.size()) cnt++;
        }

        cout << cnt << '\n';
    }
}