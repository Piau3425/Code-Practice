	#include <iostream>
	using namespace std;

	int f(int x){
		return 2*x-3;
	}

	int g(int x, int y){
		return 2*x+y-7;
	}

	int h(int x, int y, int z){
		return 3*x-2*y+z;
	}

	int eval(){
		string input;
		cin >> input;
		if(input[0] == 'f'){
			int x = eval();
			return f(x);
		}
		if(input[0] == 'g'){
			int x = eval();
			int y = eval();
			return g(x, y);
		}
		if(input[0] == 'h'){
			int x = eval();
			int y = eval();
			int z = eval();
			return h(x, y, z);
		}

		return stoi(input);
	}

	int main(){
		cout << eval();
	}