#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;

int len, tmp;
vector<int> diff;

int main(){
    while(cin >> len){
        bool jolly = true;
        int* ary;
        ary = new int[len];
        for(int i = 0; i < len; i++)
            cin >> ary[i];

        for(int i = 0; i < len-1; i++){
            tmp = abs(ary[i+1] - ary[i]);
            diff.push_back(tmp);
        }
        sort(begin(diff), end(diff));

        for(int i = 0; i < len-2; i++){
            if(diff[i]+1 != diff[i+1])
                jolly = false;
        }

        if(jolly)
            cout << "Jolly\n";
        else
            cout << "Not jolly\n";

        diff.clear();
    }
}
