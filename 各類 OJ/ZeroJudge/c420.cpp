#include <iostream>
using namespace std;

int main(){
    int n;
    cin >> n;
    int button = 2*n-1, right = button/2+1, left = right;
    for(int i = 0; i < n; i++){
        for(int i = 1; i <= button; i++){
            if(i >= left && i <= right)
                cout << "*";
            else
                cout << "_";
        }
        left--; right++;
        cout << '\n';
    }
}