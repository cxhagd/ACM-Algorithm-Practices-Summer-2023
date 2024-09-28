#include<iostream>
using namespace std;
long long int T;
long long int n;

int main() {
	cin >> T;
	for (int i = 1; i <= T; i++) {
		cin >> n;
		if (n % 2) {
			cout << n * (n - 1) / 2<<endl;
		}
		else {
			cout << (n - 1) * (n - 2) / 2 + (n - 1) / 2 + 1<<endl;
		}
	}
}