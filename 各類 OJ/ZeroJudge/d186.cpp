#include <iostream>
#include <cmath>
using namespace std;

int main(){
    int start, end;
    while(cin >> start >> end && start != 0 && end != 0){
        int count = 0;
        for(int i = start; i <= end; i++){
            if(sqrt(i) == (int)sqrt(i))
                count++;
        }
        cout << count << endl;
    }
}