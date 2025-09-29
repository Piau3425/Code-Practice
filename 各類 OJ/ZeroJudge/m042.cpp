#include <iostream>
#include <map>
#include <iomanip>
using namespace std;

map<char, double> gmol = {
    {'C', 12.01},
    {'H', 1.008},
    {'O', 16.00},
    {'N', 14.01}
};

int multiplier(string s, int &index){
    int sum = 0;
    if(!isdigit(s[index]))
        return 1;
    else{
        while(index <= s.length() && isdigit(s[index])){
            sum *= 10;
            sum += s[index] - '0';
            index++;
        }
        return sum;
    }
}

int main(){
    
    int m;
    cin >> m;
    while(m--){
        string s;
        char ele;
        double sum = 0;
        cin >> s;
        for(int i = 0; i < s.length();){
            ele = s[i];
            i++;
            sum += gmol[ele] * multiplier(s, i);
        }

        cout << fixed << setprecision(3) << sum << '\n';
    }
}