#include<iostream>
using namespace std;
long long int a, b, p,c;
long long int ans = 1;
long long int base;
long long int yu = 1;

int main() {

	cin >> a >> b >> p;
	base = a;
	c = b;
	while (b > 0) {

		if (b & 1) {
            
			yu = (ans * base) % p;
			ans *= base;
            ans%=p;

		}
		base *= base;
        base%=p;
		b >>= 1;
	}
	printf("%lld^%lld mod %lld=%lld", a, c, p, yu);
}