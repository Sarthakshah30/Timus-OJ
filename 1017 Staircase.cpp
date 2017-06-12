#include<iostream>
#include<cstring>

using namespace std;

long long int dp[502][500];
long long int calculate(int bricks,int limit);

int main(){
	int n;
	cin>>n;
	memset(dp,-1,sizeof(dp));
	cout<<calculate(n,n-1)<<endl;
}

long long int calculate(int bricks,int limit){
	if(bricks==1 && limit>0)
	return 1;
	if(bricks==0 && limit>=0)
	return 1;
	if(bricks>1 && limit<=1)
	return 0;
	long long int &ans = dp[bricks][limit];
	if(ans!=-1)
	return ans;
	ans=0;
	for(int i = 1 ; i<=limit ; i++){
		int remain=bricks-i;
		if(remain<i)
		ans+=calculate(remain,remain);
		else
		ans+=calculate(remain,i-1);
	}
	return ans;
}





