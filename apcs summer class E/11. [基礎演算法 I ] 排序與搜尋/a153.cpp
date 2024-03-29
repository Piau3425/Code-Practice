#include <iostream>
#include <cmath>
using namespace std;

double f(double x){
    return 2 - exp(x);
}

double solve(double a, double b){
    double m = (a+b)/2;
    if(b-a < 1e-8 || f(m) == 0)
        return m;
    else if(f(m)*f(a) > 0)
        return solve(m, b);
    else
        return solve(a, m);
}

int main(){
    printf("%06f", round(solve(0, 1)*pow(10, 6)) / pow(10, 6));

}
