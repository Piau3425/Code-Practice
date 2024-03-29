#include <iostream>
#include <cmath>
using namespace std;

struct coord{
    float x;
    float y;
};

int main(){
    int total;
    float sum = 0;
    cin >> total;
    coord pt[total];
    for(int i = 0; i < total; i++){
        cin >> pt[i].x >> pt[i].y;
    }

    for(int i = 0; i < total-1; i++){
        sum += pt[i].x*pt[i+1].y-pt[i].y*pt[i+1].x;
    }
    sum += pt[total-1].x*pt[0].y-pt[total-1].y*pt[0].x;

    printf("%.2f", fabs(sum/2));
}
