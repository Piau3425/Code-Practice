#include <iostream>
#include <iomanip>
using namespace std;

int a, b, c, sTotal, eTotal, diff;

int main(){
    scanf("%d:%d:%d", &a, &b, &c);
    sTotal = a*3600+b*60+c;
    scanf("%d:%d:%d", &a, &b, &c);
    eTotal = a*3600+b*60+c;

    if(sTotal <= eTotal){
        diff = eTotal - sTotal;
        cout << setw(2) << setfill('0') << diff/3600 << ":" << setw(2) << setfill('0') << diff%3600/60 << ":" << setw(2) << setfill('0') << diff%3600%60 << endl;
    }
    else{
        diff = eTotal - sTotal + 24*3600;
        printf("%02d:%02d:%02d", diff/3600, diff%3600/60, diff%3600%60);
    }
}
