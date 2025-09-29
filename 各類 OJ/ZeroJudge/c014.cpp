#include <iostream>
using namespace std;

int main(){
    int a, b, flag, count;
    while(cin >> a >> b && a+b != 0){
        count = 0;
        while(a > 0 && b > 0 || flag){
            if(a%10 + b%10 + flag >= 10){
                count++;
                flag = 1;
            }
            else
                flag = 0;
            a /= 10; b /= 10;
        }

        if(!count)
            cout << "No carry operation.\n";
        else
            cout << count << " carry operation" << (count == 1 ? "" : "s") << ".\n";
    }
}