#include <iostream>
using namespace std;

int main(){
	int n;
	string input, one = "one";
	cin >> n;
	while(n--){
		cin >> input;
		if(input.length() == 5)	
			cout << 3;
		else{
			int match = 0;
			for(int i = 0; i < 3; i++)
				if(input[i] == one[i])
					match++;
			
			if(match >= 2)
				cout << 1;
			else
				cout << 2;
		}
		
		cout << '\n';
	}
}