#include <iostream>
using namespace std;

int main(){
    string s1, s2;
    while(cin >> s1 >> s2){
        int it1 = s1.length()-1, it2 = s2.length()-1;
        while(it1+1 && it2+1){
            if(s1[it1] == s2[it2])
                it1--;
            it2--;
        }

        if(!(it1+1))
            cout << "Yes\n";  
        else
            cout << "No\n";
    }
}