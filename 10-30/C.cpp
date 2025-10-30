#include<iostream>
#include<vector>
#include<queue>
using namespace std;
#define int long long
const int N=1e3+6,inf=2e3;
typedef pair<int,int> pi;
int g[N][3],n;
queue<pi>q;
int f[N][4];
int min(int x,int y,int z){
	return min(min(x,y),z);
}
void dfs(int x){
	if(x==0){
		return;
	}
	int a=g[x][1],b=g[x][2];
	dfs(a);
	dfs(b);

	// camera
	f[x][0]=min(f[a][0],f[a][1],f[a][2])+min(f[b][0],f[b][1],f[b][2])+1;
	
	//no camera, require father camera
	f[x][1]=min(f[a][0],f[a][2])+min(f[b][0],f[b][2]);
	
	//no camera, not require father camera
	f[x][2]=min(
		f[a][0]+min(f[b][0],f[b][2]),
		f[b][0]+min(f[a][0],f[a][2]));
		
//	cout<<x<<":"<<f[x][0]<<":"<<f[x][1]<<":"<<f[x][2]<<endl;
}
signed main(){
	cin>>n;
	q.push({0,1});
	for(int i=1;i<=n;i++){
		int fa=q.front().first,nb=q.front().second;
		q.pop();
		int x;
		cin>>x;
		if(x==0){
			g[i][0]=fa;
			g[fa][nb]=i;
			q.push({i,1});
			q.push({i,2});
		}
	}
	f[0][0]=inf;
	f[0][1]=inf;
	f[0][2]=0;
	dfs(1);
	cout<<min(f[1][0],f[1][2],f[1][1]+1)<<endl;
}
/*
12
0 0 -1 0 -1 0 -1 0 -1 0 -1 -1

11
0 0 -1 0 -1 0 -1 0 -1 0 -1

10
0 0 -1 0 -1 0 -1 0 -1 0

8
0 0 0 0 0 0 0 0
*/