#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    int total, loop = 1;
    while(cin >> total){
        long long int pro, maxp = -1e9, num[total];
        for(int i = 0; i < total; i++)
            cin >> num[i];

        for(int i = 0; i < total; i++){
            for(int j = i; j < total; j++){
                if(i == j)
                    pro = num[j];
                else
                    pro *= num[j];

                maxp = max(maxp, pro);
                //cout << pro << " " << maxp << endl;
            }
        }


        if(maxp < 0)
            maxp = 0;
        cout << "Case #" << loop << ": The maximum product is " << maxp << "." << endl;
        loop++;
    }
}
