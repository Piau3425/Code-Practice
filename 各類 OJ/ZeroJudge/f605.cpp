#include <iostream>
#include <algorithm>

using namespace std;

int d1, d2, d3, loop, Rdiff, Wdiff, avg, sum = 0, cnt;

int main(){
    cin >> loop >> Wdiff;

    for(int i = 0; i < loop; i++){
        cin >> d1 >> d2 >> d3;

        avg = (d1+d2+d3)/3;
        Rdiff = max({d1, d2, d3}) - min({d1, d2, d3});

        if(Rdiff >= Wdiff){
            cnt++;
            sum += avg;
        }
    }

    cout << cnt << " " << sum;
}
