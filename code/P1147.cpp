#include<iostream>
#include<cmath>
using namespace std;
int n;
int k1;
int k2;
int main() {
	cin >> n;
	for (k1 = (int)sqrt(2*n); k1 > 1; k1--) {
		if (2*n % k1 == 0) {
			k2 = 2 * n / k1;
			if ((k1 + k2) % 2 == 1) {
				
				cout << ((k2 - k1 + 1) / 2) << " " << (( k2+k1  - 1) / 2) << endl;
				
			}
		}
	}
return 0;
}