#include<iostream>
#include<cstring>

using namespace std;

int dp[60002];
int calculate(int n);

int main(){
	int n;
	cin>>n;
	memset(dp,-1,sizeof(dp));
	cout<<calculate(n)<<endl;
}

int calculate(int n){
	if(n==0)
	return 0;
	if(dp[n]!=-1)
	return dp[n];
	dp[n]=9999999;
	for(int i = 1 ; i*i<=n ; i++){
		dp[n]=min(dp[n],calculate(n-(i*i))+1);
	}
	return dp[n];
}

