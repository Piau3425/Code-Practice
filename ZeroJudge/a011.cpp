#include <iostream>
#include <sstream>
using namespace std;

int main(){
    string input, split;
    stringstream ss;
    int count;
    while(getline(cin, input)){
        count = 0;
        ss.clear();
        ss.str(input);
        while(ss >> split){
            if(split.find("-") != string::npos)
                count++;
            count++;
        }
        cout << count << '\n';
    }
}