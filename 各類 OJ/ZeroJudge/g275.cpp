#include <iostream>
using namespace std;

int loop, s1[8], s2[8];

int main(){
    cin >> loop;

    for(int j = 0; j < loop; j++){
        string output = "";
        for(int i = 0; i < 7; i++)
            cin >> s1[i];
        for(int i = 0; i < 7; i++)
            cin >> s2[i];

        if(!(s1[1] != s1[3] && s2[1] != s2[3] && s1[1] == s1[5] && s2[1] == s2[5]))
            output += 'A';

        if(!(s1[6] == 1 && s2[6] == 0))
            output += 'B';

        if(!(s1[1] != s2[1] && s1[3] != s2[3] && s1[5] != s2[5]))
            output += 'C';

        if(output == "")
            cout << "None\n";
        else
            cout << output << '\n';
    }
}