#include <iostream>
using namespace std;

string s;

int main(){
    getline(cin, s);

    for(int i = 0; s[i] != '\0'; i++){
        if(ispunct(s[i]) || isblank(s[i]))
            cout << s[i];
        else if(isupper(s[i]))
            printf("%c", s[i]+13-(s[i]+13-'A'+1 > 26)*26);
        else if(islower(s[i]))
            printf("%c", s[i]+13-(s[i]+13-'a'+1 > 26)*26);
    }
}
