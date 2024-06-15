#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    string input;
    vector<string> v;
    int count = 0;
    cin >> input;

    sort(input.begin(), input.end());

    do{
        v.push_back(input);
        count++;
    } while(next_permutation(input.begin(), input.end()));

    cout << count << '\n';
    for(string s : v)
        cout << s << '\n';
}