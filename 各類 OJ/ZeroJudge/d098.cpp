#include <iostream>
#include <sstream>
using namespace std;

int main(){
    stringstream ss;
    string input, num;
    int sum;
    bool flag;
    while(getline(cin, input)){
        sum = 0;
        ss.clear();
        ss.str(input);
        while(ss >> num){
            flag = true;
            for(char c : num){
                if(!isdigit(c)){
                    flag = false;
                    break;
                }
            }

            if(flag)
                sum += stoi(num);
        }
        
        cout << sum << '\n';
    }
}