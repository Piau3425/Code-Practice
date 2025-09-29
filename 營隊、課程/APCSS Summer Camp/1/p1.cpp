#include <bits/stdc++.h>
using namespace std;

int main() { ios::sync_with_stdio(0); cin.tie(0);
    int n, px, py, mx, my, cx, cy;
    cin >> n;
    while (n--) {
        cin >> px >> py >> mx >> my >> cx >> cy;
        int dx = cx-px, dy = cy-py;

        if (dy*mx != dx*my) cout << "No\n";
        else if (!mx && !my) {
            if (!dx && !dy) cout << "Yes\n";
            else cout << "No\n";
        }
        else {
            if (dx * mx >= 0 && dy * my >= 0) cout << "Yes\n";
            else cout << "No\n";
        }
    }
}