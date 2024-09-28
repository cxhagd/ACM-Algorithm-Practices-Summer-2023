#include<iostream>
#include<cstring> 
#include<algorithm>
using namespace std;
string a;
string b;
int main(){
	cin>>a;
	b=a;
	reverse(a.begin(),a.end());
	if(a==b){
		cout<<"yes"<<endl;
	}else{
		cout<<"no"<<endl;
		
	}
}