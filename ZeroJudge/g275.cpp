#include <iostream>
using namespace std;

int loop, s1[8], s2[8], none = 0;

int main(){
    cin >> loop;

    for(int j = 0; j < loop; j++){
        for(int i = 0; i < 7; i++)
            cin >> s1[i];
        for(int i = 0; i < 7; i++)
            cin >> s2[i];

        if(!(s1[1] != s1[3] && s2[1] != s2[3] && s1[1] == s1[5] && s2[1] == s2[5]))
            cout << "A";
        else
            none++;

        if(!(s1[6] == 1 && s2[6] == 0))
            cout << "B";
        else
            none++;

        if(!(s1[1] != s2[1] && s1[3] != s2[3] && s1[5] != s2[5]))
            cout << "C";
        else
            none++;

        if(none == 3)
            cout << "None";

        none = 0;
        cout << endl;
    }
}
