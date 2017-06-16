#include<bits/stdc++.h>

using namespace std;
int n;

int main(){
	cin>>n;
	vector< pair<int,int> > vec;
	for(int i = 0 ; i < n  ;i++){
		int x,y;
		cin>>x>>y;
		vec.push_back(make_pair(y,x));
	}
	sort(vec.begin(),vec.end());
	int count=0;
	int prev=0;
	for(int i = 0 ;i < n ;i++){
		if(vec[i].second > prev){
			count++;
			prev=vec[i].first;
		}
	}
	cout<<count<<endl;
}
