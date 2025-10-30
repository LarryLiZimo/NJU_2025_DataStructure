#include<iostream>
using namespace std;
const int N=2e4+6;
const int D=1e4+2;
int a[N],b[N],n,t[N],v[N];
int ans[N],u[N];

void dfs(int lef,int rig,int x,int y,int dep){
	if(lef>rig){
		if(x>y){
			return;
		}
		throw 1;
	}
	//cur is a[lef]
	int mid=v[a[lef]],lef_sz=mid-x,rig_sz=y-mid;
	dfs(lef+1,lef+lef_sz,x,mid-1,dep+1);
	if(!u[dep]){
		u[dep]=1;
		ans[dep]=a[lef]-D;
	}
	dfs(lef+lef_sz+1,rig,mid+1,y,dep+1);
}
int main(){
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		a[i]+=D;
		t[a[i]]=i;
	}
	for(int i=1;i<=n;i++){
		cin>>b[i];
		b[i]+=D;
		v[b[i]]=i;
	}
	dfs(1,n,1,n,1);
	for(int i=1;u[i];i++){
		cout<<ans[i]<<" ";
	}
	cout<<endl;
}