#include <iostream>
using namespace std;

int maxx = -999, maxT = -999, t, score, loop, wrong = 0, sum;

int main(){
    cin >> loop;

    for(int i = 0; i < loop; i++){
        cin >> t >> score;

        if(score == -1){
            wrong++;
            continue;
        }
        if(score > maxx){
            maxx = score;
            if(maxT = -999 || maxT != score)
                maxT = t;
        }
    }

    sum = maxx-loop-wrong*2;
    if(sum < 0)
        sum = 0;

    cout << sum << " " << maxT;
}
