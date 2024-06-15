#include <iostream>
#include <vector>
using namespace std;

int main(){
    int s, t, n, m, r, asum = 0, bsum, diff, minn = 1e9, count = 0;
    bool flag;
    cin >> s >> t >> n >> m >> r;
    vector<vector<int>> a(s, vector<int>(t)), b(n, vector<int>(m));

    for(int i = 0; i < s; i++)
        for(int j = 0; j < t; j++)
            cin >> a[i][j];
    
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
            cin >> b[i][j];
            
    for(auto avl : a)
    	for(auto val : avl)
    		asum += val;
	
    for(int i = 0; i + s - 1 < n; i++){
        for(int j = 0; j + t - 1 < m; j++){
            bsum = 0; flag = true; diff = 0;
            for(int k = i; flag && k < i + s; k++){
                for(int h = j; flag && h < j + t; h++){
                    if(a[k-i][h-j] - b[k][h]){
                        diff++;
                        if(diff > r)
                            flag = false;
                    }
                    bsum += b[k][h];
                }
            }

            if(flag){
                count++;
                minn = min(abs(asum - bsum), minn);
            }
        }
    }
	if(minn == 1e9) minn = -1;
    cout << count << '\n' << minn;
}