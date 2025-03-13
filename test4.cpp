#include <bits/stdc++.h>
using namespace std;
#define f first
#define s second
#define pii pair<int,int>
#define pb push_back
int main(){
    int t; cin>>t;
    while(t--){
        int m,k; cin>>m>>k; char c;
        string enc="RYB",enc2="WRYOBPGD";
        map<int,map<int,int>> board,board2;
        for(int i=0;i<m;i++)for(int j=0;j<m;j++){
            cin>>c;if(c!='W')board[i][j]|= (1<<enc.find(c));
        }
        
        //for(int i=0;i<m;i++,cout<<endl)for(int j=0;j<m;j++)cout<<board[i][j]<<" ";
        
        for(int K=0;K<k;K++){
            for(int i=0;i<m;i++)for(int j=0;j<m;j++){
                board2[i][j]|=board[i-1][j];
                board2[i][j]|=board[i+1][j];
                board2[i][j]|=board[i][j-1];
                board2[i][j]|=board[i][j+1];
                board2[i][j]|=board[i][j];
            }
            for(int i=0;i<m;i++)for(int j=0;j<m;j++)board[i][j]=board2[i][j];
        }

        for(int i=0;i<m;i++,cout<<endl)for(int j=0;j<m;j++)cout<<enc2[board[i][j]];
        
        if(t)cout<<endl;
    }
    return 0;
}
