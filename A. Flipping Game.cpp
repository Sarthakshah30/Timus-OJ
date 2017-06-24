#include<iostream>
#include<cstring>

using namespace std;

int main(){
	int n;
	cin>>n;
	int array[n];
	int sum=0;
	for(int i = 0 ; i< n ; i++){
		cin>>array[i];
		if(array[i]){
			array[i]*=-1;
			sum++;			
		}
		else{
			array[i]=1;
		}
	}
	int dp[n];
	dp[0]=array[0];
	int maxi=array[0];
	for(int i = 1 ; i < n ; i++){
		dp[i]=max(dp[i-1]+array[i],array[i]);
		if(maxi<dp[i])
		maxi=dp[i];
	}
	cout<<sum+maxi<<endl;
}
