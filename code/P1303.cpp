
#include<iostream>
#include<cstring>

using namespace std;
int a[50001];
char ca[50001];
int sa, sb, sc;
char cb[50001];
int b[50001];
int c[50001];
int main() {
	cin >> ca;
	cin >> cb;
	sa = strlen(ca);
	sb = strlen(cb);
	for (int i = 0; i < sa; i++) {
		a[sa - i] = ca[i] - '0';
	}
	for (int i = 0; i < sb; i++) {
		b[sb - i] = cb[i] - '0';
	}
	sc = sa + sb;
	for (int i = 1; i <= sa; i++) {
		for (int j = 1; j <= sb; j++) {
 			c[i + j - 1] += a[i] * b[j];
			c[i + j] += c[i + j - 1] / 10;
			c[i + j - 1] %= 10;
		}
	}
	while(c[sc] == 0&&sc>1) {
		sc--;
	}
	for (int i = sc; i > 0; i--) {
	printf("%d",c[i]);
	}
 cout<<endl;

}