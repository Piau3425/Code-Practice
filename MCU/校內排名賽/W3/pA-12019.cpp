#include <iostream>
using namespace std;

main() {
	int n, m2d[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
	string week[] = {"Friday", "Saturday", "Sunday", "Monday", "Tuesday", "Wednesday", "Thursday"};
	for (cin >> n; n; n--) {
		int m, d;
		cin >> m >> d;
		for (int i = 0; i < m-1; i++) d += m2d[i];
		cout << week[d%7] << endl;
	}
}