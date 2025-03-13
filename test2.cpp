#include <bits/stdc++.h>
using namespace std;
#define f first
#define s second
#define pb push_back
#define pii pair<int,int>
struct cmp {
    bool operator()(const pii &a, const pii &b) { //用bit實作不重複字母之字典序
        if(a.f!=b.f)return a.f>b.f;
        if((a.s&-a.s)==(b.s&-b.s))return a.s>b.s;
        return (a.s&-a.s)>(b.s&-b.s);
    }
};
int main(){
	int r,Cas=0;
	while(cin>>r && r){
		int n,tmp; cin>>n;
		//  { 當前節點總和 , 底下包含哪些節點 (bit實作) }
		priority_queue<pii,vector<pii>,cmp> pq;
		vector<int> onum(n);
		vector<string> tree(n,"");
		for(int i=0;i<n;i++){
			cin>>onum[i];
			pq.push({ onum[i], 1<<i });
		}
		int R=r-1,N=n-1;
//		cout<<(R-N%R)%R<<endl;
		for(int i=0;i<(R-N%R)%R;i++)pq.push({0,0});
		int sum=0,down_node=0;
		while( int(pq.size())>1 ){
			sum=0,down_node=0;
			int k=min(r, int(pq.size()));
		//	cout<<r<<" "<<pq.size()<<" "<<k<<endl;
			for(int i=0; i<k ;i++){
				int a=pq.top().f, b=pq.top().s;
				sum+=a;
				down_node|=b;
				for(int j=0;j<n;j++) if(b&1<<j) tree[j]=char(i+'0')+tree[j];
			//	for(auto&v:tree)cout<<v<<" ";cout<<endl;
				pq.pop();
			}
		//	cout<<sum<<" "<<max_layer+1<<" "<<down_node<<endl;
			pq.push({sum , down_node });	
		}
		double avg=0.0;
		for(int i=0;i<tree.size();i++)avg += tree[i].size()*onum[i];
		cout<<fixed<<setprecision(2)<<"Set "<<++Cas<<"; average length "<<avg/sum<<endl;
		for(int i=0;i<tree.size();i++)cout<<"    "<<char(i+'A')<<": "<<tree[i]<<endl;
		cout<<endl;
	}
	return 0;
}