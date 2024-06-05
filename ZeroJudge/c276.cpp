#include <iostream>
using namespace std;

int main(){
    string ans, guess;
    cin >> ans;
    int n;
    cin >> n;
    while(n--){
        int A = 0, B = 0;
        cin >> guess;
        for(int i = 0; i < 4; i++){
            for(int j = 0; j < 4; j++){
                A += (i == j && ans[i] == guess[j]);
                B += (ans[i] == guess[j]);
            }
        }
        B -= A;

        cout << A << "A" << B << "B\n";
    }
}