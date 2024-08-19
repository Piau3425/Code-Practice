#include <iostream>
using namespace std;

int main(){
    double n;
    cin >> n;
    
    int grade = n/5.29;
    int ans = grade + (n - grade*5.29 > 0);
    cout << min(ans, 15);

    /*for (int i = 0; i <= 15; i++) if (5.29*i >= n) {
        cout << i;
        return 0;
    }
    cout << 15;*/
}