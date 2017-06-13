#include<iostream>
#include<cstring>

using namespace std;

int array[101];
int n;
long long int dp[102][2];
long long int calculate(int index,int lastbit);

int main(){
	cin>>n;
	for(int i = 0 ; i<n ; i++)
	cin>>array[i];
	memset(dp,-	1,sizeof(dp));
	cout<<calculate(0,array[0])<<endl;
}

long long int calculate(int index,int lastbit){
	if(index>=n-1 && lastbit==1)
	return 1;
	if(index>=n-1)
	return 0;
	if(dp[index][lastbit]!=-1)
	return dp[index][lastbit];
	dp[index][lastbit]=0;
	dp[index][lastbit]+=calculate(index+1,lastbit|array[index+1]);
	dp[index][lastbit]+=calculate(index+1,lastbit&array[index+1]);
	return dp[index][lastbit];
}

