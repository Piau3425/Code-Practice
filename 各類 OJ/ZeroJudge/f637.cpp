#include <iostream>
using namespace std;

string input;
int idx = 0;

int decode(int pixel){
    char c = input[idx++];
    if(c == '0')
        return 0;
    if(c == '1')
        return pixel*pixel;
    if(c == '2')
        return decode(pixel/2) + decode(pixel/2) + decode(pixel/2) + decode(pixel/2);
}

int main(){
    int m;
    cin >> input >> m;
    cout << decode(m);
}