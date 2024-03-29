#include <iostream>
#include <vector>
using namespace std;

int gcd(int a, int b){
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

int lcm(int a, int b){
    return a / gcd(a, b) * b;
}

int main(){
    while(1){
        int total;
        cin >> total;
        if(total == 0)
            break;
        vector<int> num;

        for(int i = 0; i < total; i++){
            int tmp;
            cin >> tmp;
            num.push_back(tmp);
        }

        int ans = lcm(num[0], num[1]);
        for(int i = 2; i < total; i++){
            ans = lcm(ans, num[i]);
        }

        cout << ans << endl;
    }
}
