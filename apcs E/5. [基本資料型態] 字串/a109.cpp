#include <iostream>
#include <stack>
#include <cmath>
using namespace std;

int main(){
    int loop;
    cin >> loop;
    cin.ignore();
    for(int k = 0; k < loop; k++){
        string s;
        getline(cin, s);

        int len = 1, notwo = 0;
        float a = 0, b = s.length();

        for(int i = 0; s[i] != '\0'; i++){
            if(s[i] != '0' && s[i] != '1')
                notwo = 1;
        }
        if(notwo == 1){
            cout << "-1" << endl;
            continue;
        }

        for(int i = 0; s[i] != '\0'; i++){
            if(s[i] != '0' && s[i] != '1'){
                cout << "-1" << endl;
                break;
            }
            if(s[i+1] != '\0' && s[i] == s[i+1] && len <= 6)
                len++;
            else{
                //cout << endl;
                stack<int> leng;
                for(int j = 0; j < 3; j++){
                    leng.push(len%2);
                    //cout << len << " " << len%2 << endl;
                    len /= 2;
                }
                cout << s[i];
                while(!leng.empty()){
                    cout << leng.top();
                    leng.pop();
                }
                cout << " ";
                a++;
                len = 1;
            }
        }
        cout << round(a*4/b*100) << "%" << endl;
    }
}
