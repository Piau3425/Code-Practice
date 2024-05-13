#include <iostream>
#include <vector>
#include <cmath>
#include <iomanip>
using namespace std;

bool check(int a, int b){
    for(int i = 2; i <= a; i++){
        if(a%i == 0 && b%i == 0)
            return false;
    }
    return true;
}

int main(){
    int n;
    while(cin >> n && n != 0){
        double t = 0, x = 0; // t=總數對   X=多少對數互質
        vector<int> v(n);
        for(int i = 0; i < n; i++)
            cin >> v[i];
        for(int i = v.size(); i > 1; i--)
            t += i-1;
        for(int i = 0; i < v.size()-1; i++){
            for(int j = i+1; j < v.size(); j++){
                if(v[i] < v[j] ? check(v[i], v[j]) : check(v[j], v[i]))
                    x++;
            }
        }

        if(x == 0)
            cout << "No estimate for this data set.\n";
        else
            cout << fixed << setprecision(6) << sqrt(t*6.0/x) << endl;
    }
}
