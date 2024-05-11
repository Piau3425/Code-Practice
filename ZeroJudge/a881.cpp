#include <iostream>
#include <vector>
using namespace std;

int getMax(int start, int end, vector<int> eat){
    int maxx = -1e9;
    for(int i = start; i <= end; i++)
        maxx = max(maxx, eat[i]);
    return maxx;
}

int getAvg(int start, int end, vector<int> eat){
    double sum = 0, avg;
    for(int i = start; i <= end; i++)
        sum += eat[i];
    return sum/(end-start+1);
}

int main(){
    int z;
    cin >> z;
    for(int i = 0; i < z; i++){
        int m, w;
        cin >> m >> w;
        vector<int> eat;
        for(int j = 0; j < m; j++){
            int tmp;
            cin >> tmp;
            eat.push_back(tmp);
        }
        for(int j = 0; j < w; j++){
            int a, b, c;
            cin >> a;
            switch(a){
                case 1:
                    cin >> b >> c;
                    cout << getMax(b, c, eat) << endl;
                    break;
                case 2:
                    cin >> b >> c;
                    cout << getAvg(b, c, eat) << endl;
                    break;
                case 3:
                    cin >> b;
                    cout << eat[b] << endl;
                    break;
            }
        }
    }
}