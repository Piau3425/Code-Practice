#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    while (n--) {
        int x, sum = 0;
        cin >> x;
        for (int i = 1; i <= sqrt(x); i++) 
            if (!(x%i)) sum += (i <= sqrt(x))+(i < sqrt(x));
        cout << sum << '\n';
    }
}