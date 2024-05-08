#include <iostream>
using namespace std;

int main(){
    string input;
    cin >> input;

    for(int i = 0; i < input.length(); i++){
        cout << string(input.begin()+i, input.end()) + string(input.begin(), input.begin()+i) << endl;
    }
}
