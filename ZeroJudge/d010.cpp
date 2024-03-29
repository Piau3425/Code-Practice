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
            cout << "盈數\n";
        else if(sum < num)
            cout << "虧數\n";
        else
            cout << "完全數\n";
    }
}
