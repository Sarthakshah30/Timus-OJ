#include<iostream>
#include<algorithm>
#include<vector>
#include<cstring>

using namespace std;
long long int dp[19][19];
int n,k;
long long int calculate(int index,int lastIndex);

int main(){
	memset(dp,-1,sizeof(dp));
	cin>>n>>k;
	long long int ans = 0;
	for(int i = 1 ; i< k ; i++){
		ans+=calculate(1,-1);
	}
	cout<<ans<<endl;
}

long long int calculate(int index,int lastIndex){
	if(index==n)
	return 1;
	if(dp[index][lastIndex]!=-1)
	return dp[index][lastIndex];
	long long int ans = 0;
	for(int i = 1 ; i< k ; i++){
		ans+=calculate(index+1,lastIndex);
	}
	if(lastIndex+1!=index){
		ans+=calculate(index+1,index);
	}
	return dp[index][lastIndex]=ans;
}
