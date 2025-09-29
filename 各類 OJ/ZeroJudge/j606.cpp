#include <iostream>
using namespace std;

int main(){
	int k, q, r, idx;
	string input;
	cin >> k >> q >> r;
	cin >> input;
	string old = input, save[r];
	for(auto &s : save)
		s = "";
		
	for(int i = 0; i < q; i++){
		for(int j = 0; j < k; j++){
			cin >> idx;
			input[idx-1] = old[j];
		}
		old = input;
		
		for(int j = 0; j < r; j++)
			save[j] += input[j];
	}
	
	for(int i = 0; i < r; i++)
		cout << save[i] << '\n';
}