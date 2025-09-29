#include <iostream>
using namespace std;

int Amplitude, Frequency, loop;

int main(){
    cin >> loop;
    for(int k = 0; k < loop; k++){
        cin >> Amplitude >> Frequency;

        for(int q = 0; q < Frequency; q++){
            for(int i = 1; i <= Amplitude; i++){
                for(int j = 0; j < i; j++)
                    cout << i;
                cout << endl;
            }
            for(int i = Amplitude-1; i >= 1; i--){
                for(int j = 0; j < i; j++)
                    cout << i;
                cout << endl;
            }
            cout << endl;
        }
    }
}
