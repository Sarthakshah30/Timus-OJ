#include <bits/stdc++.h>
using namespace std;
 
long long DP[44];
 
void init()
{
	DP[0] = 1;
	DP[1] = 2;
	for(int i=2;i<44;++i)
		DP[i] = DP[i-1] + DP[i-2];	
}
 
void solve(int n,int k)
{
	if(n==0)
		return;
	if(n==1)
	{
		cout << (k-1);
		return;
	}
	if(k>DP[n-1])
	{
		cout << "10";
		solve(n-2,k-DP[n-1]);
	}
	else
	{
		cout << "0";
		solve(n-1,k);
	}
}
 
int main()
{
	init();
	int n,k;
	cin >> n >> k;
	if(k>DP[n])
		cout << "-1";
	else
		solve(n,k);
	return 0;
}
