#include <iostream>
using namespace std;

void discount(double *a, double *b){
     if(*a == *b)
        *b /= 2;
}
int main(){
    double p1, p2;
    cout << "Original price:" << endl;
    cin >> p1 >> p2;
    discount(&p1, &p2);
    cout << "Price after discount:" << endl;
    cout << p1 << " " << p2 << endl;
    return 0;
}
