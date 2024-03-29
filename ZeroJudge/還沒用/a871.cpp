#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

struct coord{
    float x;
    float y;
};
int total;

int main(){
    while(cin >> total){
        float sum = 0;
        coord pt[total];
        for(int i = 0; i < total; i++){
            cin >> pt[i].x >> pt[i].y;
        }

        for(int i = 0; i < total-1; i++){
            sum += pt[i].x*pt[i+1].y-pt[i].y*pt[i+1].x;
        }
        sum += pt[total-1].x*pt[0].y-pt[total-1].y*pt[0].x;

        sum = fabs(sum/2);
        cout << fixed << setprecision(2) << sum << endl;
    }
}
