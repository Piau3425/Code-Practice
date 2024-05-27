#include <iostream>
using namespace std;

#define diff (input-3)%10
string tian = "癸甲乙丙丁戊己庚辛壬";
string ground = "亥子丑寅卯辰巳午未申酉戌";

int main(){
    int input;
    string output;
    
    while(cin >> input){
        cout << tian[diff] << ground[diff] << endl;
    }
}