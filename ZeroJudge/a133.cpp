#include <iostream>
#include <vector>
using namespace std;

int count;

int lcs(vector<int> s1, vector<int> s2, vector<vector<int>> length){
    for(int i = 0; i < s1.size(); i++)
        length[i][0] = 0;
    for(int i = 0; i < s2.size(); i++)
        length[0][i] = 0;

    for(int i = 1; i < s1.size(); i++){
        for(int j = 0; j < s2.size(); j++){
            if(s1[i] == s2[j])
                length[i][j] = length[i-1][j-1] + 1;
            else
                length[i][j] = max(length[i-1][j], length[i][j-1]);
        }
    }

    return length[s1.size()-1][s2.size()-1];
}

int main(){
    int n, m, tower = 1;
    while(cin >> n >> m && n != 0 && m != 0){
        count = 0;
        vector<int> a(n+1), b(m+1);
        vector<vector<int>> dp(n+1, vector<int>(m+1));
        for(int i = 1; i <= n; i++)
            cin >> a[i];
        for(int j = 1; j <= m; j++)
            cin >> b[j];
        
        count = lcs(a, b, dp);

        cout << "Twin Towers #" << tower++ << '\n';
        cout << "Number of Tiles : " << count << "\n\n";
    }
}