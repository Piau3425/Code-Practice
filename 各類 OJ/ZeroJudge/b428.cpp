#include <iostream>
using namespace std;

int diff;
string a, b;

int main(){
    while(getline(cin, a)){
        getline(cin, b);
        diff = b[0]-a[0];
        if(diff < 0)
            diff += 26;
        cout << diff << endl;
    }

}
