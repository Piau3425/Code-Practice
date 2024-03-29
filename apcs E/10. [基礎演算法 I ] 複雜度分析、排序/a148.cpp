//應該可以把map改成創vector時用二維，就不會那麼亂

#include <iostream>
#include <map>
#include <algorithm>
#include <cstring>
#include <vector>
using namespace std;

int main(){
    string s;
    while(getline(cin, s)){
        bool noExist[129];
        memset(noExist, true, sizeof(noExist));
        map<int, int> freq;
        vector<int> asci;
        for(int i = 0; i < s.size(); i++){
            if(noExist[s[i]]){
                asci.push_back(s[i]);
                freq[s[i]] = 1;
                noExist[s[i]] = false;
            }
            else{
                freq[s[i]]++;
            }
        }

        for(int i = 0; i < asci.size(); i++){
            for(int j = 0; j < asci.size()-i-1; j++){
                if(freq[asci[j]] > freq[asci[j+1]] || (freq[asci[j]] == freq[asci[j+1]] && asci[j] < asci[j+1])){
                    swap(asci[j], asci[j+1]);
                }
            }
        }

        for(int i = 0; i < asci.size(); i++){
            cout << asci[i] << " " << freq[asci[i]] << endl;
        }
        s.clear();
    }
}
