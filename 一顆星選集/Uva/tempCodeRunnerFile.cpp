#include <iostream>
using namespace std;

int main(){
    int a, b, flag, count;
    while(cin >> a >> b && (a+b != 0 || flag)){
        count = 0;
        while(a > 0 && b > 0){
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
            cout << count << " carry operation" << "s\0"[count==1] << ".\n";
    }
}