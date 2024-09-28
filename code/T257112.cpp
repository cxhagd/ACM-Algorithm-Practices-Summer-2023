#include<iostream>
using namespace std;

long long int n;

int main(){
	cin>>n;
	for(int i=2;i<n;i++){
		if(n%i==0){
			cout<<(n/i);
			return 0;
		}
	}
	
}