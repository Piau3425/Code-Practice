#include <iostream>
#include <stack>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n;
    cin >> n;
    while(n--){
        string input;
        stack<char> s;
        int count = 0;
        cin >> input;
        for(int i = 0; i < input.length(); i++){
            if(input[i] == '.')
                continue;

            if(input[i] == 'p')
                s.push('p');
            
            if(input[i] == 'q' && !s.empty()){
                count++;
                s.pop();
            }
        }

        cout << count << '\n';
    }
}