#include <iostream>
#include <cmath>
using namespace std;

int n, loop;
long long int maxnum, start;

int main(){
    cin >> loop;

    for(int d = 0; d < loop; d++){
        cin >> n;
        maxnum = pow(10, n);
        start = sqrt(pow(10, n-1));
        //cout << start << " " << maxnum << endl;
        long long int ans;
        for(long long int i = start; (i*i)/maxnum == 0; i++){
            long long int num = i*i;
            int isit = 1;
            while(num != 0){
                int tmp = num%10;
                //cout << i*i << " " << tmp << endl;
                if(tmp%2 != 0)
                    isit = 0;
                num /= 10;
            }
            //cout << i*i << " " << isit<< endl;
            if(isit == 1){
                ans = i*i;
                break;
            }
        }
        cout << ans << endl;
    }
}
