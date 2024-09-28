#include<iostream>
#include<cmath>
long long int a;
int aa[33];
long long int b;
int main() {

	scanf("%ld", &a);
	for (int i = 1;; i++) {
		aa[i] = a % 2;
		a = a / 2;
		if (a == 0) {
			break;
		}
		if (a == 1) {
			aa[i + 1] = 1;
			break;
		}
	}
	
	for (int i = 1; i <= 16; i++) {
		int temp = aa[i];
		aa[i] = aa[i + 16];
		aa[i + 16] = temp;
	}

	for (int i = 1; i <= 32; i++) {
		b += aa[i] * pow(2, i-1);
	}

	printf("%ld", b);
}