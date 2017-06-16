#include<bits/stdc++.h>
#define MOD 1000000001
using namespace std;

int dp[50001][301][2];
int n,a,b;
int calculate(int index,int cont_count, int lastsong);

int main(){
	memset(dp,-1,sizeof(dp));
	cin>>n>>a>>b;
	long long int ans = calculate(0,a,1);
	ans=(ans+calculate(0,b,2))%MOD;
	cout<<ans<<endl;
}

int calculate(int index,int cont_count, int lastsong){
	if(index==n)
	return 1;
	if(dp[index][cont_count][lastsong]!=-1)
	return dp[index][cont_count][lastsong];
	long long int temp=0;
	if(lastsong==1){
		temp=(temp+calculate(index+1,1,2))%MOD;
		if(cont_count!=a)
		temp=(temp+calculate(index+1,cont_count+1,1))%MOD;
	}
	if(lastsong==2){
		temp=(temp+calculate(index+1,1,1))%MOD;
		if(cont_count!=b)
		temp=(temp+calculate(index+1,cont_count+1,2))%MOD;
	}
	return dp[index][cont_count][lastsong]=temp;
}
