#include<iostream>
#include<cstring>
#include<cstdio>
#include<cstdlib>
using namespace std;
int x, y;
char a[1001];
int an;
int b[1001];
int c[1001];
int num = 0;
char ans[1001];
int cn = 0;
int main() {
	cin >> x;
	cin >> a;
	cin >> y;
	int an = strlen(a);
	for (int i = 0; i < an; i++) {
		if (a[i] >= '0' && a[i] <= '9') {
			b[an - i] = a[i] - '0';
		}
		if (a[i] >= 'A' && a[i] <= 'F') {
			b[an - i] = a[i] - 'A' + 10;
		}
	}
	int base = 1;
	for (int i = 1; i <= an; i++) {
		num += b[i] * base;
		base *= x;
	}
	for (int i = 1; num != 0; i++) {
		c[i] = num % y;
		num = num / y;
		cn = i;
	}

	for (int i = 1; i <= cn; i++) {
		if (c[i] <= 9) {
			ans[i] = c[i] + '0';
		}
		else {
			ans[i] = c[i] - 10 + 'A';
		}
	}
	for (int i = cn; i >= 1; i--) {
		cout << ans[i];
	}
}