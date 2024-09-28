#include<iostream>
#include<map>

using namespace std;

long long int N,C;
long long int a[200100]; 

long long int ans=0;
map<long long int, long long int>m;
int main(){
	cin>>N>>C;
	for(int i=1;i<=N;i++){
		cin>>a[i];
		m[a[i]]++;
		a[i] -= C;
	}
	for(int i=1;i<=N;i++){
		ans += m[a[i]];
	} 
	cout<<ans<<endl;
	
}


 