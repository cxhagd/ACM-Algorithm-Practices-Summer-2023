#include<iostream>
#include<set> 
using namespace std;
set<string> s;
int n;
int main(){
	cin>>n;
	for(int i=1;i<=n;i++){
		string a;
		cin>>a;
		s.insert(a);
	}
	cout<<s.size()<<endl;
	}