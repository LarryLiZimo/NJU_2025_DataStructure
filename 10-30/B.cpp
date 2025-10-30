#include<iostream>
#include<vector>
using namespace std;
const int N=1e5+6;
int n,a[N*4];
vector<int>g[N];
int dfs(int i,int dep){
	if(a[i]==-1){
		return i;
	}
	int x=a[i];
	i=dfs(i+1,dep+1);
	g[dep].push_back(x);
	i=dfs(i+1,dep+1);
	return i;
}
int main(){
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	dfs(1,1);
	for(int i=1;!g[i].empty();i++){
		if(i%2==1){
			for(int j=0;j<g[i].size();j++){
				cout<<g[i][j]<<" ";
			}
		}else{
			for(int j=g[i].size()-1;j>=0;j--){
				cout<<g[i][j]<<" ";
			}
		}
		cout<<endl;
	}
}