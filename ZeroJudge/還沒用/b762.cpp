#include <iostream>
using namespace std;

int main(){
    int k = 0, tmpk = 0, d = 0, a = 0, t;
    string killmsg[8] = {
        "You have slain an enemie.",
        "You have slain an enemie.",
        "KILLING SPREE!",
        "RAMPAGE~",
        "UNSTOPPABLE!",
        "DOMINATING!",
        "GUALIKE!",
        "LEGENDARY!"
    };
    string diemsg[4] = {
        "You have been slained.",
        "You have been slained.",
        "You have been slained.",
        "SHUTDOWN."
    };
    cin >> t;
    for(int i = 0; i < t; i++){
        string input;
        cin >> input;
        if(input == "Get_Kill"){
            k++; tmpk++;
            cout << killmsg[tmpk-1 > 7 ? 7 : tmpk-1] << endl;
        }
        else if(input == "Die"){
            cout << diemsg[tmpk > 3 ? 3 : tmpk] << endl;
            tmpk = 0; d++;
        }
        else
            a++;
    }

    cout << k << "/" << d << "/" << a;
}