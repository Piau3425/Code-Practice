#include <iostream>
using namespace std;

long long m(int x){
	long long sum = 1;
	while(x--) sum *= x+1;
	return sum;
}

int main(){
	int a, b;
	while(cin >> a >> b) cout << m(a)/m(b)/m(a-b) << '\n';
}