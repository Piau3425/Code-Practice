#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

bool cmp(pair<int, int> a, pair<int, int> b){
        return a.first > b.first;
}

int main(){
    int n;
    cin >> n;

    for(int i = 0; i < n; i++){
        int m;
        cin >> m;
        pair<int, int> c[m];
        for(int j = 0; j < m; j++){
            int x, y;
            cin >> x >> y;
            c[j].first = x;
            c[j].second = y;
        }
        cout << "----------------------------\n";
        sort(c, c+m, cmp);
        /*for(auto a : c)
            cout << a.first << " " << a.second << endl;*/
        int maxH = 0;
        double sum = 0;
        for(int j = 0; j < m-1; j++){
            if(c[j+1].second > c[j].second && c[j+1].second > maxH){
                sum += sqrt(pow(x-c[j+1].first, 2)+pow(c[j+1].second-maxH, 2)); // x應為前面的山坡x投影到當前山坡上的點
                maxH = c[j+1].second;
            }
        }
        cout << sum;
    }
}