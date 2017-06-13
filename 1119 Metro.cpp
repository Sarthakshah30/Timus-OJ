#include<iostream>
#include<cmath>
#include<cstring>
#include<utility>
#include<vector>

using namespace std;

double dp[1005][1005];
int xt,yt;
vector< pair<int,int> > vec;
double calculate(int x,int y);

int main(){
	scanf("%d%d",&yt,&xt);
	int n;
	scanf("%d",&n);
	memset(dp,-1,sizeof(dp));
	for(int i = 0 ; i< n ; i++){
		int x,y;
		scanf("%d%d",&y,&x);
		vec.push_back(make_pair(--x,--y));
	}
	double ans  = calculate(0,0)*100;
	if(ceil(ans)-ans > 0.5)
	n=ans;
	else
	n=ceil(ans);
	printf("%d\n",n);
}

double calculate(int x,int y){
	if(x==xt && y==yt)
	return 0;
	if((dp[x][y])>=0)
	return dp[x][y];
	dp[x][y]=99999999;
	if(x+1<=xt)
	dp[x][y]=min(dp[x][y],1+calculate(x+1,y));
	if(y+1<=yt)
	dp[x][y]=min(dp[x][y],1+calculate(x,y+1));
	for(int i = 0 ; i<vec.size() ; i++){
		pair<int,int> temp = vec[i];
		if(temp.first==x && temp.second==y){
			dp[x][y]=min(dp[x][y],1.41421356237+calculate(x+1,y+1));
			break;
		}
	}
	return dp[x][y];
}



