#include <iostream>
#include <algorithm>
using namespace std;

bool check(string x){
    if(x == string(x.rbegin(), x.rend()))
        return true;
    return false;
}

int main(){
    string input;
    int n;
    
    cin >> n;
    for(int i = 0; i < n; i++){
        int count = 0, sum;
        cin >> input;
        
        do{
            sum = stoi(input) + stoi(string(input.rbegin(), input.rend()));
            input = to_string(sum);
            count++;
        } while(!check(input));

        cout << count << " " << input << "\n";
    }
}