    #include <iostream>
    #include <string>
    using namespace std;

    int main(){
        string s;
        char c;
        while(getline(cin, s)){
            for(int i = 0; i < s.length(); i++){
                string o = "";
                while(i < s.length() && s[i] != ' '){
                    o += s[i];
                    i++;
                }
                cout << string(o.rbegin(), o.rend())+' ';
            }
            cout << '\n';
        }
    }