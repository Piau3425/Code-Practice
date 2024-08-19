#include <iostream>
#include <iomanip>
using namespace std;

double BMI(double a, double b) {
    return a / (b*b);
}

int main() {
    double w, h;
    cin >> w >> h;
    cout << fixed << setprecision(3) << BMI(w, h) << endl;
}