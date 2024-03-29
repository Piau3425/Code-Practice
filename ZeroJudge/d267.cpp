#include <iostream>
#include <cstring>
using namespace std;

string str;
int loop, freq[28], maxx = -1;
char ch;

int main(){
    cin >> loop;
    cin.ignore();
    for(int k = 0; k < loop; k++){
        getline(cin, str);
        for(int i = 0; str[i] != '\0'; i++){
            if(str[i] >= 'a' && str[i] <= 'z'){
                freq[str[i]-'a']++;
                maxx = max(maxx, freq[str[i]-'a']);
            }
            else if(str[i] >= 'A' && str[i] <= 'Z'){
                freq[str[i]-'A']++;
                maxx = max(maxx, freq[str[i]-'A']);
            }
        }
        for(int i = 0; i < 28; i++){
            if(freq[i] == maxx){
                ch = i+'a';
                cout << ch;
            }
        }
        cout << endl;

        maxx = -1;
        memset(freq, 0, sizeof(freq));
    }
}
