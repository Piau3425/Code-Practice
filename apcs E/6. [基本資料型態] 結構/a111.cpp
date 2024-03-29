#include <iostream>
using namespace std;

struct customer{
    int arr;
    int time;
};

int main(){
    int total;
    cin >> total;
    customer cus[total];

    for(int i = 0; i < total; i++){
        cin >> cus[i].arr >> cus[i].time;
    }

    int maxque = 0, pass = 1, leaveT = cus[0].arr + cus[0].time, que = 0;
    for(int t = cus[0].arr; t <= cus[total-1].arr; t++){
        if(t == leaveT){ //被服務的顧客時間到
            //cout << "time up " << pass << endl;
            if(que > 0){
                que--;
                leaveT = t + cus[pass].time;
                pass++;
            }
        }

        if(t == cus[pass+que].arr){  //新顧客上門
            //cout << "get new customer" << endl;
            if(t < leaveT){
                que++;
            }
            else{
                leaveT = t + cus[pass].time;
                pass++;
            }
        }
        maxque = max(que, maxque);
        //cout << "t = " << t << " maxque = " << maxque << endl;
    }

    cout << maxque;
}
