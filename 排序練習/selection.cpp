/*選擇排序法*/
#include <iostream>
#include <vector>
#include <sstream>
using namespace std;

int main(){
    int minIndex, g = 0;
    vector<int> v;
    stringstream ss;
    string input;
    getline(cin, input);
    ss.str(input);
    while(ss >> input)
        v.push_back(stoi(input));

    for(int i = 0; i < v.size()-1; i++){
        minIndex = i;
        for(int j = i+1; j < v.size(); j++)
            if(v[j] < v[minIndex])
                minIndex = j;
        
        swap(v[i], v[minIndex]);
    }

    for(int val : v)
        cout << val << " ";
}