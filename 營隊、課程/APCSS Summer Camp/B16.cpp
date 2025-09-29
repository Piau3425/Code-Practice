#include <bits/stdc++.h>
using namespace std;

int main(){
    int t[3], n, c = 1, sum;
    while (cin >> n) {
        sum = 0;
        while (n--) {
            for (auto &i : t) cin >> i;
            sort(t, t+3);
            if(t[0] + t[1] > t[2]) sum++;
        }
        cout << "Case " << c++ << ": " << sum << '\n';
    }
}