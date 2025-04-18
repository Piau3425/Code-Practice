#include <iostream>
using namespace std;

void Towers(int n, char a, char b, char c){
	if(n == 1){
		cout << "Move ring " << n << " from " << a << " to " << c << endl;
	}
	else{
		Towers(n-1,a,c,b);
		cout << "Move ring " << n << " from " << a << " to " << c << endl;
		Towers(n-1,b,a,c);
	}
}
int main() { ios_base::sync_with_stdio(0); cin.tie(0);
	int n;
	cin >> n;
	Towers(n,'A','B','C');
}