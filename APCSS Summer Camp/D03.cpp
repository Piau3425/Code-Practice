#include <iostream>
using namespace std;

int num, i = 1;

int main(){
    while(cin >> num){
        int sum = 0, tmp = num;
        for(int i = 1; i < tmp; i++){
            if(num%i == 0){
                sum += i+num/i;
                if(i == num/i)
                    sum -= i;
            }

            tmp = num/i;
        }
        sum -= num;
        if(sum > num)
            cout << "abundant";
        else if(sum < num)
            cout << "deficient";
        else
            cout << "perfect";
    }
}
