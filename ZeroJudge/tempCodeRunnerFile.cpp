#include <iostream>
#include <sstream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    stringstream ss;
    string input;
    
    int i = 0;
    while(getline(cin, input)){
        vector<int> v(input.length()/2+1);
        ss.clear();
        ss.str(input);
        while(ss >> v[i++]){}

        sort(v.begin(), v.end());

        for(int k = 0; k < v.size()-1; k++){
            for(int j = i; j < v.size(); j++)
                cout << v[k] << " " << v[j] << '\n';
        }
    }
}