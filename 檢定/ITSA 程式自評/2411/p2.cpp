#include <iostream>
using namespace std;

main() {
    int n, t;
    for (cin >> n; n; n--) {
        cin >> t;
        cout << int(t/1.5) + 1 << '\n';
    } 
}