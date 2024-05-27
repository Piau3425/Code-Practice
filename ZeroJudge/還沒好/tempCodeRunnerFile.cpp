#include <iostream>
using namespace std;

int main(){
    int input;

    string tian = "癸甲乙丙丁戊己庚辛仁", ground = "亥子丑寅卯辰巳午未申酉戌";
    while(cin >> input){
        cout << tian[(input-3)%10] + ground[(input-3)%10] + "\n";
    }
}