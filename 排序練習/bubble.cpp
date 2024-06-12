#include <iostream>
#include <vector>
#include <sstream>
using namespace std;

int main(){
    vector<int> v;
    stringstream ss;
    string input;
    getline(cin, input);
    ss.str(input);
    while(ss >> input)
        v.push_back(stoi(input));

    for(int i = 0; i < v.size()-1; i++)
        for(int j = 0; j < v.size()-1-i; j++)
            if(v[j] > v[j+1])
                swap(v[j], v[j+1]);

    for(auto val : v)
        cout << val << ' ';
}